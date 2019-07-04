## 需求分析
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;学生成绩信息管理系统是一个信息化管理软件，可以帮助学校快速录入学生信息，并且对学生的信息进行基本的增，删，改操作，还可以根据排序功能宏观地看到学生成绩从高到低的排列，随时掌握学生近期的学习状态，可以随时将学生信息保存到磁盘文件中，以便查看。
<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;学生成绩信息管理系统功能包括数据的录入、修改、插入、查询、删除，平均成绩的计算，列出不及格学生清单以及用文件把数据保存起来。
## 系统功能结构图
![系统功能结构图](https://github.com/kunnkkk/Students-achievement-management-system/blob/master/images/0.png)
## 功能介绍
### 1．密码系统
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;系统设有加密功能，如果输入正确，则在提示密码正确后能使用功能，否则则提示密码错误，并在两秒后才能重新输入。输入的密码以‘*’替换。

 ![密码系统](https://github.com/kunnkkk/Students-achievement-management-system/blob/master/images/1.png)

### 2．录入信息
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;录入信息功能对学号唯一性、年龄合理性、性别输入格式、课程编号和名称对应性、学分合理性以及成绩合理性有常规的容错。当用户输入的内容有错时会进行提醒，而输入的课程名称与编号不对应则会询问是否要查看对应表，再进行输入。

 ![录入信息](https://github.com/kunnkkk/Students-achievement-management-system/blob/master/images/2.png)

### 3．修改信息
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;修改信息可根据需要更改的项目进行更改，而每一个项目都可以根据学号或者姓名两种方式来更改。若有同名同姓的情况，系统也能将所有同名同姓的人输出，再从其中选择相应学号修改信息。另外，当选择修改课程编号（或名称）时，其所对应的课程名称（或编号）也会相应改变，保证唯一性。

 ![修改信息](https://github.com/kunnkkk/Students-achievement-management-system/blob/master/images/3.png)

### 4．插入信息
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;插入功能能将学生基本信息及成绩插入到用户选择的人的前面，如果被选择的人不存在则无法插入，而输入了已存在的学号就会提示该学生已存在。

 ![插入信息](https://github.com/kunnkkk/Students-achievement-management-system/blob/master/images/4.1.png)
 ![插入信息](https://github.com/kunnkkk/Students-achievement-management-system/blob/master/images/4.2.png)

### 5．查询信息
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;查询信息功能也是分为根据学号查询和根据姓名查询，同名同姓的情况也能够全部显示。这个功能在拥有大数据量的情况下十分有用，只会显示符合条件的信息。

 ![查询信息](https://github.com/kunnkkk/Students-achievement-management-system/blob/master/images/5.png)

### 6．删除信息
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;删除功能可以选择要删除学生全部信息还是部分课程信息，可以通过选择学号或者姓名删除。

 ![删除信息](https://github.com/kunnkkk/Students-achievement-management-system/blob/master/images/6.png)

### 7．显示信息
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;显示信息排版特点是不把所有选修课的信息放在同一行，而是该学生选了几门课程，课程信息就有几行，方便用户阅读观看。

 ![显示信息](https://github.com/kunnkkk/Students-achievement-management-system/blob/master/images/7.png)

### 8．计算平均成绩及排序
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;计算了学生各门选修成绩的平均课程成绩后，成绩可以由高到低进行排序，其他所有信息也会跟着移动，并且有排名显示。

 ![计算排序](https://github.com/kunnkkk/Students-achievement-management-system/blob/master/images/8.png)

### 9．显示不及格信息
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;不及格信息只会显示该学生不及格的课程，而不会把所有课程都显示出来。如没有不及格信息显示“无记录”。

 ![不及格信息](https://github.com/kunnkkk/Students-achievement-management-system/blob/master/images/9.png)
