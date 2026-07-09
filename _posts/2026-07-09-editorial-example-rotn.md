---
title: "Editorial example of how to insert ROTN in an article"
description: "Rosario Turco's blog with free game downloads for the blind"
keywords: ["Articles", "chess", "free", "blind", "visually impaired"]
categories: Blog
---

# How to insert ROTN into your content

by Rosario Turco

ROTN is Rot Notation, an ASCII text format to describe chess positions accessible to screen readers like NVDA.

To avoid interrupting reading, the ROTN position should not be placed in the text. It should be placed in a separate file and linked.

## 1. Workflow for Blogs, Websites and Markdown

We use an HTML template to be filled in once for each position.

_Step 1: Download the template_  
[Download template-html](https://github.com/RedYouMan/redyouman.github.io/raw/main/_posts/templates/template-html.7z)  
It is a base file. Unzip it and you get the html file.

_Step 2: Fill in and Rename_  
Open the file with Notepad. Paste your position into the textarea.  
Save it immediately with a descriptive name. Examples:
`carlsen-nakamura-2025-34.html` or `italy-2026-stalemate.html`  
Important: never leave the name as `template.html`

Edit the data in the file.

_Step 3: Upload the file to your website folder and Link it in Markdown_  
Upload the file to your website folder.  
In your article write like this:
White to move and wins in 2.
[See and Copy ROTN position: Carlsen vs Nakamura m.34](/rotn/carlsen-nakamura-2025-34.html)
When clicked, a simple page opens with 1 textarea and 1 "Copy" button. The user copies and returns to the article. NVDA reads everything correctly.

## 2. Workflow for eBook ePub and Accessible PDF

In eBooks javascript may not work. We use .txt attachments

_Step 1: Download and Fill the template_  
[Download template-ebook](https://github.com/RedYouMan/redyouman.github.io/raw/main/_posts/templates/template-ebook.7z)  
Unzip it, fill in the data and save it with a name different from the template and that is descriptive.  
Example name: `ch3-pos2.rotn.txt`

_Step 2: Insert it into the eBook_  
Attach the file as a resource in the ePub.

_Step 3: Link it in the text_
Let's analyze the position.
<a href="ch3-pos2.rotn.txt" download>Download ROTN file </a>
The reader downloads and opens the .txt with NVDA.

## 3. Important note on IT and EN

The tag order is fixed: `T;V;B;N;M;P;` for Italian  
The tag order is fixed: `T;V;W;B;M;P;` for English

The `V` tag sets the language:  
`V:B;` or `V:N;` = Italian. So use `B:` and `N:`  
`V:W;` or `V:B;` = English. So use `W:` and `B:`

## 4. Content of the HTML template to download

The full code is in the file you downloaded in step 1.
Open it with Notepad and fill in only the textarea.
