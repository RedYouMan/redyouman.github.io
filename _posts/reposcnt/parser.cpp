#include <iostream>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <limits>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/miller_rabin.hpp>
#include <vector>
#include "proto.h"
#include <cctype> // Added for isdigit
#define MAXSTACK 100

using namespace boost::multiprecision;
using cpp_int = boost::multiprecision::cpp_int;

// stackCommand contains the commands. They are associated for each position to numPar
std::string stackCommand[] = {"clear", "exit", "help", "save", "gcd", "pow", "module", "log2", "log10", "sqrtint", "primeR", "primeG", "primeM", "perfect", "perfectlist", "mersenne", "mersennelist", "divisors", "factors", "primeslist", "series", "factorial", "collatz", "ifibonacci", "zeta", "nroot", "exp", "bin", "dec", "reponelist", "stronglist", "seqcunn", "rsakey", "repone", "add", "subt", "divide", "mul", "primelast", "lastV", "ndigits", "genprime", "assign", "countP", "pushM", "popM", "readM", "plprimes", "plperfect"};
// numValues contains how many parameters there are for the command.
int numValues[] = {0, 0, 0, 0, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 1, 1, 2, 4, 2, 1, 1, 5, 2, 1, 1, 1, 2, 2, 3, 1, 1, 2, 2, 2, 2, 0, 0, 1, 1, 1, 0, 0, 0, 0, 2, 2};
int stackExclude[] = {0, 1, 2, 3, 10, 11, 12, 13, 14, 15, 16, 19, 22, 24, 29, 30, 31, 32, 47, 48};
cpp_int InputValues[5];

cpp_int recursiveOutput;
cpp_int Mem;
cpp_int countPrimes;
std::vector<cpp_int> Primes;
bool inFor;
bool inCount;
const int precValue = 1;
const int precOp = 2;
int OpType = 0;
cpp_int countCommand = 0;

// parser.cpp

// Funzione per rimuovere spazi
std::string trim(const std::string s)
{
  size_t start = s.find_first_not_of(" ");
  if (start == std::string::npos)
    return "";
  size_t end = s.find_last_not_of(" ");
  return s.substr(start, end - start + 1);
}

// estrae il  comando richiesto corretto
int extractCommand(const std::string input1)
{

  int command = -1;

  std::string bufInput;
  bufInput.clear();
  size_t posizione_parentesi_aperta;
  // identifico prima eventuali spazi di inizio

  size_t start = input1.find_first_not_of(" ");
  if (start != std::string::npos)
  {
    posizione_parentesi_aperta = input1.find('(');
    if (posizione_parentesi_aperta != std::string::npos)
    {
      bufInput = input1.substr(start, posizione_parentesi_aperta - start);
    }
    else
    {

      std::cout << "extractCommand - Invalid Command" << std::endl;
      return (command);
    }
  }
  else
  {
    std::cout << "Wrong Command\n";
    std::cout << "extractCommand - There is a problem on open bracket " << bufInput << std::endl;
    return (command);
  }
  bufInput = trim(bufInput);

  std::string str;
  str.clear();
  if (bufInput.empty())
  {
    std::cout << "Wrong Command\n";
    std::cout << "extractCommand - bufInput empty\n";
    return (-1);
  }
  if (bufInput[0] == ';')
  {
    // adapt_for

    str = input1.substr(start + 1, posizione_parentesi_aperta - start - 1);

    command = findStackCommand(str);
  }
  else
  {
    command = findStackCommand(bufInput);
  }
  if (command == -1)
  {
    std::cout << "Wrong Command\n";
    std::cout << "extractCommand - There is a problem to understand on findCommand of " << bufInput << std::endl;
    return (-1);
  }
  // int numP = numValues[command];

  return command;
}

int extractValues(const std::string input, int comando)
{
  // ritorna 0 se non ci sono valori altrimenti 1 e va
  // esaminato ValoriInput[]
  // cerca quello che è dentro le due parentesi o ta parentesi e la virgola o tra le virgole
  cpp_int par = 0;
  int numPar = numValues[comando];
  if (numPar == 0)
  {
    return (0); // non ci sono parametri
  }
  std::string val;
  size_t posizione_parentesi_aperta = input.find('(');

  if (posizione_parentesi_aperta == std::string::npos)
  {
    std::cout << "Wrong Command\n";
    std::cout << "extractValues - There is a problem on open bracket\n";
    return (-1);
  }
  size_t posizione_parentesi_chiusa = input.find(')');
  if (posizione_parentesi_chiusa == std::string::npos)
  {
    std::cout << "Wrong Command\n";
    std::cout << "extractValues - There is a problem on close bracket\n";
    return (-1);
  }

  // pulizia dei ValoriInput prima di valorizzarli
  for (int i = 0; i < numPar; i++)
  {
    InputValues[i] = 0;
  }
  if (numPar == 1)
  {
    val.clear();
    val = input.substr(posizione_parentesi_aperta + 1, posizione_parentesi_chiusa - posizione_parentesi_aperta - 1);
    val = trim(val);
    if (val.empty())
    {
      std::cout << "Wrong Command\n";
      std::cout << "extractValues - There isn't a value\n";
      return (-1);
    }
    if (numericOk(val) == 0)
    {
      std::cout << "Wrong Command\n";
      std::cout << "extractValues - It isn't a numeric value\n";
      return (-1);
    }

    InputValues[0] = cpp_int(val);
  }
  else
  {
    // npar > 1
    std::vector<std::string> params;
    size_t start = posizione_parentesi_aperta + 1;
    size_t end = posizione_parentesi_chiusa;
    std::string params_str = input.substr(start, end - start);
    size_t pos = 0, prev = 0;
    int found_params = 0;
    while ((pos = params_str.find(',', prev)) != std::string::npos)
    {
      params.push_back(trim(params_str.substr(prev, pos - prev)));
      prev = pos + 1;
      found_params++;
    }
    params.push_back(trim(params_str.substr(prev)));
    if ((int)params.size() != numPar)
    {
      std::cout << "Wrong Command\n";
      std::cout << "extractValues - There is a problem on the number of aspected values\n";
      return (-1);
    }
    for (int i = 0; i < numPar; i++)
    {
      val = params[i];
      if (val.empty())
      {
        std::cout << "Wrong Command\n";
        std::cout << "extractValues - There aren't values\n";
        return (-1);
      }
      if (numericOk(val) == 0)
      {

        std::cout << "Wrong Command\n";
        std::cout << "extractValues - It isn't a numerix value\n";
        return (-1);
      }
      InputValues[i] = cpp_int(val);
    }
  }
  return 1;
}
int findStackCommand(const std::string com)
{
  int len = com.length();

  for (size_t i = 0; i < (sizeof(stackCommand) / sizeof(stackCommand[0])); i++)
  {
    if (com == stackCommand[i])
    {
      return static_cast<int>(i);
    }
  }

  return (-1);
}
int numericOk(const std::string &str)
{
  int len = str.length();
  for (int i = 0; i < len; i++)
  {
    if (isdigit(str[i]) == 0)
    {
      // std::cout << "It's a not numeric value or not integer value. See help\n";
      return (0);
    }
  }
  return (1);
}

int countCommas(const std::string str)
{

  int count = 0;
  int len = str.length();
  for (int i = 0; i < len; i++)
  {
    if (str[i] == ',')
    {
      count++;
    }
  }
  return (count);
}

int countOpenBrackets(const std::string mybuffer)
{
  int count = 0, len = 0;
  len = mybuffer.length();
  for (int i = 0; i < len; i++)
  {
    if (mybuffer[i] == '(')
    {
      count++;
    }
  }

  return (count);
}
int countCloseBrackets(const std::string input)
{
  int count = 0, len = 0;
  len = input.length();
  for (int i = 0; i < len; i++)
  {
    if (input[i] == ')')
    {
      count++;
    }
  }
  return (count);
}

int extractRecursiveCommand(const std::string input)
{

  int openB = 0, closeB = 0, commas = 0;
  std::string ap;
  ap.clear();
  if (input[0] == ';')
  {
    ap = input.substr(1, input.length()); // tolto -1
  }
  else
  {
    ap = input;
  }

  ap = trim(ap);
  openB = countOpenBrackets(ap);
  closeB = countCloseBrackets(ap);
  commas = countCommas(ap);

  if (openB != closeB)
  {
    std::cout << "Wrong Command\n";
    std::cout << "extractRecursiveCommand - The total of Open brackets is different from Close brackets\n";
    return (-1);
  }
  if (openB == 1)
  {
    return 0; // it isn't recursive ok
  }

  std::string buf = ap.substr(0, 6);
  if (buf == "primeR" || buf == "primeG" || buf == "primeM")
  {

    std::cout << "Wrong Command\n";
    std::cout << "extractRecursiveCommand - It isn't possible to use of primeR, primeG and primeM in recursive commands\n";
    return (-1);
  }
  if (commas == 0 && openB > 2)
  {
    std::cout << "Wrong Command\n";
    std::cout << "extractRecursiveCommand - There is a problem with commas and open brackets \n";
    return (-1);
  }
  // From here the command is recursive ...
  size_t posOpenBracket;
  size_t posComma;
  size_t nextPosOpenBracket;
  size_t posCloseBracket;
  posOpenBracket = ap.find("(");
  if (posOpenBracket == std::string::npos)
  {
    std::cout << "Wrong Command\n";
    std::cout << "extractRecursiveCommand - There is a problem on open bracket\n";
    return (-1);
  }
  std::string strBuf; // it contains end operation

  strBuf = ap.substr(0, posOpenBracket + 1);

  std::string numBuf;
  numBuf.clear();
  numBuf = ap.substr(0, posOpenBracket);

  int posBuf = findStackCommand(numBuf);
  int numParameters = numValues[posBuf];
  std::string subInput;
  subInput = ap.substr(posOpenBracket + 1, input.length() - posOpenBracket - 1);
  subInput = trim(subInput);
  std::string str;
  std::string truncateSubInput;
  int command = 0;
  int status = 0;
  int len = 0;
  nextPosOpenBracket = 0;
  int countOp = numParameters;
  ;

  // we are in subInput
  while (countOp > 0)
  {
    str.clear();
    truncateSubInput.clear();

    // numbers and command are beetween comma and brackets and after we see if number or command

    posComma = subInput.find(',');
    if (posComma == std::string::npos)
    {
      if (countOp == numParameters && closeB > 2)
      {
        std::cout << "Wrong Command\n";
        std::cout << "extractRecursiveCommand - There is a problem on num parameters or on close bracket\n";
        return -1;
      }
      else
      {
        posComma = 0;
      }
    }

    posCloseBracket = subInput.find(')');
    if (posCloseBracket == std::string::npos)
    {
      std::cout << "Wrong Command\n";
      std::cout << "extractRecursiveCommand - There is a problem on close bracket\n";
      return (-1);
    }
    nextPosOpenBracket = subInput.find('(');
    if (nextPosOpenBracket == std::string::npos)
    {
      if (countOp == numParameters)
      {
        std::cout << "Wrong Command\n";
        std::cout << "extractRecursiveCommand - There is a problem on open brackets\n ";
        return -1;
      }
      else
      {
        nextPosOpenBracket = subInput.length(); // in the case of second step position
      }
    }
    if (countOp == numParameters)
    {
      nextPosOpenBracket = 0;
    }

    if (nextPosOpenBracket < posComma)
    {

      // In the first position we have a number or a command
      subInput = trim(subInput);
      if (isdigit(subInput[0]) == 1)
      {
        str = subInput.substr(nextPosOpenBracket, posComma - nextPosOpenBracket);
        OpType = precValue;
      }
      else
      {
        str = subInput.substr(nextPosOpenBracket, posCloseBracket - nextPosOpenBracket + 1);
        OpType = precOp;
      }

      len = subInput.length();
      posCloseBracket++;
      posCloseBracket = subInput.find(')');
      if (posCloseBracket == std::string::npos)
      {
        std::cout << "Wrong Command\n";
        std::cout << "extractRecursiveCommand - There is a problem on close brackets\n";
        return (-1);
      }

      // two elaboration for trunk

      if (OpType == precOp)
      {
        truncateSubInput = subInput.substr(posCloseBracket, len - posCloseBracket - 1);
        truncateSubInput = trim(truncateSubInput);
      }
      else
      {
        truncateSubInput = subInput.substr(posComma, len - posComma - 1);
        truncateSubInput = trim(truncateSubInput);
      }
      subInput = truncateSubInput;
    }
    else
    {
      //    in the second position we have number or command but we can eork in the same mode

      if (commas == 0)
      {
        str = subInput.substr(posComma, posCloseBracket - posComma + 1);
      }
      else
      {
        str = subInput.substr(posComma + 1, posCloseBracket - posComma);
      }
    }
    str = trim(str);
    //     Now we can see if number or command
    if (isdigit(str[0]) == 1)
    {
      // It is a value
      strBuf = strBuf + str;
    }
    else
    {
      // it is a command
      str = trim(str);
      command = extractCommand(str);
      if (command == -1)
      {
        std::cout << "Wrong Command\n";
        std::cout << "extractRecursiveCommand - There is a problem with extractCommand\n";
        return (-1);
      }
      status = excludeCommand(command);
      if (status == -1)
      {
        std::cout << "Command " << stackCommand[command] << " not correct for recursive commands\n";

        return (-1);
      }
      status = extractValues(str, command);
      if (status == -1)
      {
        std::cout << "Wrong Command\n";
        std::cout << "extractRecursiveCommand -There is a problem with extractValues\n ";
        return (-1);
      }
      status = executeCommand(command);
      if (status == -1)
      {
        std::cout << "Wrong Command\n";
        std::cout << "extractRecursiveCommand - There is a problem on execution of the command\n";
        return (-1);
      }
      strBuf = strBuf + recursiveOutput.str();
    }

    countOp--;
    if (countOp > 0)
    {
      strBuf = strBuf + ",";
    }
  }
  strBuf = strBuf + ")";
  recursiveOutput = 0;

  command = extractCommand(strBuf);
  if (command == -1)
  {
    std::cout << "Wrong Command\n";
    std::cout << "extractRecursiveCommand - There is a problem on thenext execution of command\n";
    return -1;
  }
  status = excludeCommand(command);
  if (status == -1)
  {
    std::cout << "Command " << stackCommand[command] << " not correct for recursive commands\n";
    return (-1);
  }

  status = extractValues(strBuf, command);
  if (status == -1)
  {
    std::cout << "Wrong Command\n";
    std::cout << "extractRecursiveCommand - There is a problem with to extract values\n";
    return -1;
  }
  status = executeCommand(command);
  if (status == -1)
  {
    return (-1);
  }
  return (1);
}

int excludeCommand(int command)
{
  for (size_t i = 0; i < (sizeof(stackExclude) / sizeof(stackExclude[0])); i++)
  {
    if (command == stackExclude[i])
    {
      return (-1);
    }
  }
  return (0);
}

int primeLastOp()
{
  int status = -1;
  status = boost::multiprecision::miller_rabin_test(recursiveOutput, 25);
  return (status);
}

cpp_int lastValue()
{

  if (countCommand == 0)
  {
    std::cout << "There aren't previous operations!";
  }
  return (recursiveOutput);
}

int countSemicolon(const std::string input); // Forward declaration

int extractFor(const std::string input)
{
  // it extracts the for command
  // it returns -1 if not found or the position of the for command
  inFor = true;
  inCount = false;
  countPrimes = 0;
  Primes.clear();
  size_t posFor = input.find("for[");
  if (posFor == std::string::npos)
  {
    inFor = false;
    return (0); // it isn't a for
  }

  // extract minInterv and maxInterv
  size_t pos_col;
  pos_col = input.find(":");
  if (pos_col == std::string::npos)
  {
    std::cout << "Wrong Command\n";
    std::cout << "extractFor - There isn't the first symbol ':'\n";
    return (-1);
  }
  std::string numStart = input.substr(0, pos_col);
  cpp_int minInterv = cpp_int(numStart);
  size_t pos_col_new;
  pos_col_new = input.find(":", pos_col + 1);
  if (pos_col_new == std::string::npos)
  {
    std::cout << "Wrong Command\n";
    std::cout << "extractFor - There isn't the second symbol ':'\n";

    return (-1);
  }
  std::string numEnd = input.substr(pos_col + 1, pos_col_new - pos_col - 1);
  cpp_int maxInterv = cpp_int(numEnd);
  // end minInterv and maxInterv
  size_t pos_openBracket = input.find('[');
  size_t pos_closedBracket = input.find(']');
  if (pos_openBracket == std::string::npos || pos_closedBracket == std::string::npos || pos_closedBracket <= pos_openBracket + 1)
  {
    inFor = false;
    std::cout << "Wrong Command\n";
    std::cout << "extractFor - There is a problem on the brackets\n";
    return (-1);
  }

  std::string subInput = input.substr(pos_openBracket + 1, pos_closedBracket - pos_openBracket - 1);
  // now it extracts list commands separated by semicolons [;] between [ ] to execute
  std::string command;
  std::vector<std::string> commands;
  int status = 0;

  size_t prev = 0, posSemicolon = 0;
  int count = 0;
  while ((posSemicolon = subInput.find(';', prev)) != std::string::npos)
  {
    command = trim(subInput.substr(prev, posSemicolon - prev));
    if (!command.empty())
    {
      commands.push_back(command);
      count++;
    }
    prev = posSemicolon + 1;
  }
  // Add the last command after the last semicolon (or the only command if no semicolon)
  command = trim(subInput.substr(prev));
  if (!command.empty())
  {
    commands.push_back(command);
    count++;
  }

  if (count == 0)
  {
    inFor = false;
    std::cout << "extractFor - Warning: There aren't commands. Wrong Command\n";
    return (-1);
  }
  // now it extracts each command fron vector, it do extractCommmand and extractValues and executeCommand
  command.clear();
  cpp_int index = 0;
  std::string command2;
  if (minInterv < 1 || maxInterv < 1 || minInterv > maxInterv)
  {
    inFor = false;
    std::cout << "extractFor - Wrong interval. \n";
    return (-1);
  }
  for (index = minInterv; index <= maxInterv; index++)
  {
    for (size_t i = 0; i < commands.size(); i++)
    {
      command = commands[i];
      command = trim(command);
      command2.clear();
      (void)replaceCommand(command, index, command2);
      // here i seee if recursive commands
      status = extractRecursiveCommand(command2);
      if (status == -1)
      {
        inFor = false;
        std::cout << "Wrong Command\n";
        std::cout << "extractFor - There is a problem caused by extractRecursiveCommand\n";
        return (-1);
      }
      if (status != 1)
      {
        // comando semplice non ricorsivo
        int commandNum = extractCommand(command2);
        if (commandNum == -1)
        {
          inFor = false;
          std::cout << "Wrong Command\n";
          std::cout << "extractFor - error extract Command num\n";
          return (-1);
        }
        // exclude commnd

        status = excludeCommand(commandNum);
        if (status == -1)
        {
          inFor = false;
          std::cout << "Command " << stackCommand[commandNum] << " not correct for recursive commands\n";
          return (-1);
        }
        status = extractValues(command2, commandNum);
        if (status == -1)
        {
          inFor = false;
          std::cout << "Wrong Command\n";
          std::cout << "extractFor - There is a problem caused by extract parameters\n";
          return (-1);
        }
        (void)executeCommand(commandNum);
      }
    }
  }
  // per il conteggio dei numeri primi trovati
  if (inCount)
  {
    std::cout << "Total prime numbers: " << countPrimes << std::endl;
    inCount = false;
    if (Primes.size() > 0)
    {
      // we read Primes
      std::cout << "Prime Numbers:\n";
      for (size_t i = 0; i < Primes.size(); i++)
      {
        std::cout << Primes[i] << " ";
      }
      std::cout << std::endl;
    }
  }
  return (1);
}

int replaceCommand(const std::string str, cpp_int ind, std::string &newCommand)
{
  // it extract variable x and replaces it with ind
  size_t posX = str.find("x");
  if (posX == std::string::npos || posX >= str.size())
  {
    newCommand = str;
    return 1; // Don't use the replace
  }

  std::string str2 = str;
  str2.replace(posX, 1, ind.str());
  newCommand = str2;
  return 1;
}
int countSemicolon(const std::string input)
{
  int count = 0;
  int len = input.length();
  for (int i = 0; i < len; i++)
  {
    if (input[i] == ';')
    {
      count++;
    }
  }
  return (count);
}

void pushMem()
{
  Mem = recursiveOutput;
  return;
}

void popMem()
{
  recursiveOutput = Mem;
  // Non azzerare Mem qui, altrimenti perdi il valore memorizzato dopo il primo pop.
  // Mem = 0; // Rimuovi o commenta questa riga se vuoi che Mem mantenga il valore.
  return;
}

cpp_int readMem()
{
  return (Mem);
}
