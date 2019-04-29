# 구글 자바 스타일 가이드(Google Java Style Guide)

## 1.소개 

### 1.1 용어 노트 

### 1.2 가이드 노트 

## 2. 소스파일 기본 

### 2.1 파일 이름 

### 2.2 파일 인코딩: UTF-8

### 2.3 특별 문자

> 2.3.1 공백 문자

> 2.3.2 이스케이프 시퀀스 

> 2.3.3 Non-ASCII characters

## 3. 소스파일 구조 

### 3.1 라이센스 및 저작권 정보가 있는 경우.

### 3.2 Package 문.

### 3.3 Import 문.

> 3.3.1 No wildcard imports

> 3.3.2 No line-wrapping

> 3.3.3 Ordering and spacing
 
> 3.3.4 No static import for classes

### 3.4 클래스 선언 

> 3.4.1 Exactly one top-level declaration

> 3.4.2 Ordering of class contents
  
> 3.4.2.1 Overloads: never split

## 4. Formatting

### 4.1 Braces(중괄호)    소괄호는  parentheses

> 4.1.1 Braces are used where optional 

> 4.1.2 Nonempty blocks: K & R style

> 4.1.3 Empty blocks: may be concise

### 4.2 Block indentation: +2 spaces

### 4.3 One statement per line

### 4.4 Column limit: 100

### 4.5 Line-Wrapping(줄 바꿈)

> 4.5.1 Where to break

> 4.5.2 Indent continuation lines at least +4 spaces

### 4.6 Whitespace

> 4.6.1 Vertical Whitespace

> 4.6.2 Horizontal Whitespace

> 4.6.3 Horizontal alignment: never required (진짜 필요없는)

### 4.7 Grouping parentheses: recommended ( 소괄호 그룹잉하기 : 추천)

### 4.8 Specific constructs (특별한 구조들)

> 4.8.1 Enum classes

> 4.8.2 Variable declarations

> 4.8.3 Arrays

> 4.8.4 Switch statements

> 4.8.4.1 Indentation

> 4.8.4.2 Fall-through: commented (fall-through기법은 주석 표시해라)

> 4.8.4.3 default 문은 있어야 한다. (the default case is present)

> 4.8.5 Annotations

> 4.8.6 Comments

> 4.8.7 Modifiers

> 4.8.8 Numeric Literals

## 5. Naming

### 5.1 Rules common to all identifiers

### 5.2 Rules by identifier type

> 5.2.1 Package names

> 5.2.2 Class names

> 5.2.3 Method names

> 5.2.4 Constant names

> 5.2.5 Non-constant field names

> 5.2.6 Parameter names

> 5.2.7 Local variable names

> 5.2.8 Type variable names

### 5.3 Camel case: defined

## 6. Programming Practices

### 6.1 @Override : always used

### 6.2 Caught exceptions: not ignored (예외처리 할 곳은 반드시 예외처리 해야 한다 :  not ignored)

### 6.3 Static members: qualified using class ( static 멤버는 클래스 이름으로 접근하라)

### 6.4 Finalizers: not used

## 7.Javadoc

## 7.1 Formatting

> 7.1.1 General form

> 7.1.2 Paragraphs

> 7.1.3 Block tags

## 7.2 The summary fragment(요약 조각)

## 7.3 Where Javadoc is used

> 7.3.1 Exceptions: self-explanatory methods

> 7.3.2 Exception: overrides

> 7.3.4 Non-required Javadoc





