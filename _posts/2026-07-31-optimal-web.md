---
title: "Digital Accessibility and Autonomy in Web Portals"
description: "Technical guidelines to make web portals autonomous for blind users. 4 pillars, checklist and bibliography."
keywords:
  [
    "web accessibility",
    "digital accessibility",
    "wcag 2.2",
    "wai-aria",
    "nvda",
    "blind",
    "visually impaired",
    "accessible games",
    "free",
  ]
categories: Blog
---

# Accessibility and Autonomy in Web Portals: Technical Guidelines for the Inclusion of Blind Users

_by Rosario Turco, engineer_

## Abstract

Modern portals base interaction on visual paradigms and pointing. This approach effectively excludes users who rely on assistive technologies such as screen readers. This article analyzes the most common architectural barriers, proposes 4 design pillars, and defines a list of technologies to adopt and to avoid. The goal is to provide a technical foundation for designing portals that guarantee inclusion and operational autonomy.

With this work we aim to define an operational approach to accessibility, shifting the focus from mere regulatory compliance to the user's real ability to complete a task autonomously. The article analyzes and classifies the most common architectural barriers, introduces 4 design pillars — Perceivable, Operable, Understandable, Robust — and provides two operational lists: technologies and patterns to avoid, and technologies and patterns to adopt. A user testing methodology and a release checklist are also proposed.

The goal is to provide a technical and practical foundation for designing web portals that guarantee inclusion, usability, and operational autonomy for blind users, through the use of semantic HTML, textual notations, and "speech-first" design.

## 1. Introduction: Autonomy is Not Optional

Web accessibility is often treated as an add-on. An `alt` added late. Contrast adjusted at the end of the project. This approach produces formal compliance, not autonomy.

For a blind user using NVDA or JAWS, "accessible" means one thing: being able to complete a task from start to finish without asking for help. Buy, read, play, configure.

The difference is substantial. WCAG compliance verifies the presence of attributes. Autonomy verifies the completion of the flow. A form can have all the labels up to code, but if the "Submit" button is only reachable with a mouse, the user is blocked.

This article proposes to shift the focus: from checklist to operational capability.

## 2. Barrier Analysis: When the Portal Says "Use the Mouse"

Barriers can be classified into 5 categories. Each category blocks one aspect of autonomy.

**A. Navigation Barriers**  
_Problem_: Flat structure and unmanaged focus.  
_Example_: A dropdown menu made with `<div>`. You can't get into it with Tab. With the screen reader you only hear "clickable".  
_NVDA Impact_: The user can't find the sections. They are lost on the page.

**B. Content Barriers**  
_Problem_: Information conveyed only visually.  
_Example_: A chessboard is 64 `<img>` tags without `alt`. Or a chart is a single `canvas`.  
_JAWS Impact_: The screen reader reads "image, image, image". The content doesn't exist.

**C. Interaction Barriers**  
_Problem_: Dependency on pointer inputs and gestures.  
_Example_: A "drag & drop" to upload a file. Or a calendar where you click the dates.  
_Impact_: Without a mouse there is no way to interact. The keyboard is ignored.

**D. Technological Barriers**  
_Problem_: Incorrect use of HTML and ARIA.  
_Example_: `<span onclick="submit()">Submit</span>`. It's not a button. It's not focusable.  
_Impact_: Assistive technologies don't recognize the control. They ignore it.

**E. Control Barriers**  
_Problem_: The user cannot manage timing and states.  
_Example_: A session timeout popup after 60s with no warning. An error that appears in red but isn't read.  
_Impact_: The user loses data and doesn't understand why.

## 3. Pillar 1 - Perceivable: Every Visual Element Must Have a Textual Equivalent

If information exists only as pixels, for a screen reader it doesn't exist.

**Technical Requirements:**

1.  **Images**: Descriptive `alt`, not "image1.jpg". If decorative: `alt=""`.
2.  **Complex Content**: Charts, maps, chessboards. Require long descriptions. Solution: structured alternative text or associated data table.
3.  **The `canvas` case**: It's a black box. The browser only sees pixels. Solution: maintain a parallel DOM with the objects, and use `aria-label` or `role="img"` with a description.

_Before vs After Example_:  
Before: `<canvas id="board"></canvas>` → NVDA: "graphic"  
After: `<div role="grid" aria-label="Chessboard. White King on E1">` + 64 cells → NVDA: "Row 1, White Rook on A1"

## 4. Pillar 2 - Operable: Everything Must Work with Keyboard Only

The mouse is optional. The keyboard is not.

**Technical Requirements:**

1.  **Logical Focus Order**: Tab must follow the page reading order, left to right, top to bottom.
2.  **Visible Focus**: Always a border. If you remove it with CSS, put it back.
3.  **No Traps**: In a modal, Tab must cycle only inside the modal. Esc must close it.
4.  **Input Mapping**: Every mouse action must have a keyboard equivalent. Click → Enter/Space. Drag → arrow keys + Enter.

_Before vs After Example_:  
Before: Menu that opens only with `onmouseover`  
After: Menu that opens with `Enter`, navigated with arrows, closed with `Esc`

## 5. Pillar 3 - Understandable: Predictability and Clarity of the System

The user must always know where they are, what they are doing, and what happened.

**Technical Requirements:**

1.  **Structure**: Only one `H1` per page. Consistent H2-H3 hierarchy. Used to "scan" the page.
2.  **Forms**: Every `input` must have an associated `label` with `for="id"`. Placeholder is not enough.
3.  **Feedback**: Errors and states must be announced. Use `aria-live="polite"` for notifications.  
    Coloring red is not enough. Text is needed: "Error: password must be 8 characters".
4.  **Titles**: Every page must have a unique `title`. Used to orient between tabs.

## 6. Pillar 4 - Robust: Semantic Code for Future Assistive Technologies

Assistive technologies read the DOM, not the CSS.

**Technical Requirements:**

1.  **HTML First**: Use `button` for buttons, `a` for links, `nav` for navigation. Don't reinvent.
2.  **ARIA is the Last Resort**: Use it for dynamic states `aria-expanded`, `aria-pressed`. Not to replace a button.
3.  **Valid DOM**: No duplicate IDs. No conflicting roles.
4.  **Compatibility**: Test with NVDA + Firefox, JAWS + Chrome, VoiceOver + Safari. If it works there, it works everywhere.

_Before vs After Example_:  
Before: `<div class="btn" onclick="...">Save</div>`  
After: `<button type="submit">Save</button>`

## 7. Technologies and Patterns to Avoid: The Blacklist

These technologies break autonomy. They should be avoided or used only with a solid fallback.

1.  **`canvas` without parallel DOM**: It's pixels. The screen reader can't see inside.  
    _Alternative_: SVG + text, or data table + description.
2.  **Icon-fonts and Emoji without text**: `<i class="icon-trash"></i>`  
    _Problem_: NVDA reads "blank".  
    _Alternative_: `<button aria-label="Delete">`
3.  **Visual-only CAPTCHA**: "Select all traffic lights".  
    _Alternative_: Audio CAPTCHA, logic, or honeypot.
4.  **Scanned PDFs**: They are photos. Not selectable, not readable.  
    _Alternative_: PDF with real text and tags, or HTML.
5.  **SPAs that don't manage focus**: Page changes, but focus stays at the top and the title doesn't change.  
    _Problem_: The user doesn't know the page has changed.
6.  **Color as the only information**: "Red fields are required".  
    _Alternative_: Add `* Required` and `aria-required="true"`.
7.  **Timer without extension option**: Session expires in 2 minutes.  
    _Alternative_: Warning at 60s and "Extend" button.

## 8. Technologies and Patterns to Adopt: The Whitelist

These are the foundation for building autonomous portals.

1.  **Native Semantic HTML**: `header`, `nav`, `main`, `article`, `button`, `form`. They provide semantics for free.
2.  **ARIA for Dynamic States**: `aria-label`, `aria-expanded`, `aria-live="polite"`, `aria-describedby`. Only to fill gaps in HTML.
3.  **Keyboard API**: Handle Tab, Shift+Tab, Arrows, Enter, Esc. Test everything without a mouse.
4.  **Structured Alternative Text**: Use tables for complex data. Use `aria-live` for states.
5.  **WCAG AA Contrast**: Minimum ratio 4.5:1 for normal text. Tool: contrast calculator.
6.  **Open Data Formats**: Prefer JSON, Markdown, TXT over closed binaries.  
    _Key Concept_: "Accessible Notation". Data must be readable by voice alone. Example: instead of a graphical position, a string `e2-e4`.

## 9. The Role of Open Standards and Notations: From Visual Data to Vocal Data

The problem is not the content. It's the format.

Many data sets are designed for the eyes. To be autonomous, they must be designed for the ears.

**Anonymous Case Study "Before vs After"**

**Case A: Position on a Grid**  
_Before_: A graphical grid. The user has to ask "where is the piece?".  
_After_: A structured string: `POS: D4=White Rook`. The screen reader reads it in 2 seconds.  
_Principle_: Data must be "speech-first". This is the concept behind notations like ROTN 1.8.

**Case B: The Chart**  
_Before_: `canvas` with colored bars. Alt="Sales chart".  
_After_: Below the chart, a visually hidden HTML table:  
`Year 2024: 120k. Year 2025: 150k.`  
_Principle_: Every visualization must have a tabular equivalent.

_Thesis_: Standardizing textual notations for complex data is more important than making the `canvas` "pretty".

## 10. Testing Methodology: Validate with the End User and with NVDA

Automated tools like axe or lighthouse find 30% of problems. Only a real user finds the rest.

**Minimum Testing Procedure:**

1.  **Disable the mouse**. Can you do everything with Tab, Shift+Tab, Enter, Esc, Arrows?
2.  **Turn on NVDA**. Close your eyes. Can you understand the page structure using only H and Tab?
3.  **Run 5 Critical Tasks**: Login, Search, Form Completion, Checkout, Logout. Time them.
4.  **Metrics to Collect**:
    - Time to complete the task
    - Number of Tab presses
    - Number of errors / blockers
5.  **Golden Rule**: If an NVDA user can't finish autonomously, the portal is not finished.

## 11. Design Checklist: 10 Questions Before Release

Print this and stick it on the dev's desk.

1.  Can I navigate the entire site using only the keyboard?
2.  Is focus always visible and logical?
3.  Do all non-decorative images have a useful `alt`?
4.  Does every `input` have an associated `label`?
5.  Are errors announced and explained by voice?
6.  Do the `H1-H2-H3` titles describe the page structure?
7.  Do modals trap focus and close with `Esc`?
8.  If I disable CSS, does the content still make sense?
9.  Does the page title change on every "screen" of the SPA?
10. Can an NVDA user complete the main task without help?

If the answer to even one is "No", do not release.

## 12. Conclusions: Inclusion as Complexity Reduction

Designing for autonomy doesn't complicate. It simplifies.

An accessible portal uses less custom JavaScript, fewer `div`s, fewer heavy UI libraries. It uses more native HTML. It uses more text.

Inclusion is not a cost. It's an architectural choice: moving from "visual-only" interfaces to "data + semantics" interfaces.

The final proposal is this: let's stop chasing compliance. Let's start writing Operational Technical Specifications. Documents that don't say "use alt" but "the user must be able to complete X in Y seconds using only the keyboard".

Only then will the web stop saying "use the mouse" and start saying "welcome".

## Bibliography

- **W3C Web Accessibility Initiative**. _Web Content Accessibility Guidelines (WCAG) 2.2_. W3C Recommendation, October 5, 2023. https://www.w3.org/TR/WCAG22/
- **W3C**. _Accessible Rich Internet Applications (WAI-ARIA) 1.2_. W3C Recommendation, June 6, 2023. https://www.w3.org/TR/wai-aria-1.2/
- **W3C / WHATWG**. _HTML Living Standard_. Continuously updated. https://html.spec.whatwg.org/
- **Henry, S.L., Abou-Zahra, S., Brewer, J.** _The Role of Accessibility in a Universal Web_. In: _Proceedings of the 11th Web for All Conference_, 2014. https://dl.acm.org/doi/10.1145/2596695.2596719
- **Power, C., Petrie, H., Swallow, D., Sharp, H.** _Understanding the Use of Web-Based Interactive Applications by People with Visual Impairments_. In: _Universal Access in the Information Society_, 2012.
- **The Paciello Group**. _WCAG 2.2 Understanding Documents_. https://www.w3.org/WAI/WCAG22/Understanding/
