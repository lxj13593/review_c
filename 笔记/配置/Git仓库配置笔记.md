# Git 仓库配置笔记

## 一、进入项目目录

当前项目路径：

```powershell
E:\project\review_c
```

在终端中进入项目目录：

```powershell
cd E:\project\review_c
```


## 二、初始化 Git 仓库

```powershell
git init
```

执行后，项目目录下会生成一个隐藏文件夹：

```text
.git
```

有了 `.git` 文件夹，这个项目就变成了一个 Git 仓库。


## 三、第一次提交

查看当前文件状态：

```powershell
git status
```

把所有文件加入暂存区：

```powershell
git add .
```

提交第一个版本：

```powershell
git commit -m "初始化项目"
```


## 四、第一次使用 Git 需要配置用户信息

如果提交时报错，提示没有用户名或邮箱，可以先配置：

```powershell
git config --global user.name "你的名字"
git config --global user.email "你的邮箱"
```

查看配置是否成功：

```powershell
git config --global --list
```


## 五、日常常用命令

查看当前改动：

```powershell
git status
```

查看具体修改内容：

```powershell
git diff
```

暂存所有改动：

```powershell
git add .
```

提交改动：

```powershell
git commit -m "提交说明"
```

查看提交记录：

```powershell
git log
```


## 六、提交代码的一般流程

```powershell
git status
git add .
git commit -m "本次修改说明"
```

建议每次完成一个小功能或一组相关修改后，就提交一次。


## 七、连接 GitHub 仓库

先在 GitHub 上新建一个空仓库，然后复制仓库地址。

添加远程仓库：

```powershell
git remote add origin 仓库地址
```

把当前分支改名为 `main`：

```powershell
git branch -M main
```

第一次推送到 GitHub：

```powershell
git push -u origin main
```

之后再次推送，只需要：

```powershell
git push
```


## 八、几个重要概念

工作区：

平时写代码的地方，也就是项目文件夹。

暂存区：

执行 `git add` 后，文件会进入暂存区，表示准备提交。

本地仓库：

执行 `git commit` 后，修改会保存到本地 Git 仓库。

远程仓库：

GitHub、Gitee 等平台上的仓库，执行 `git push` 后代码会上传到远程仓库。


## 九、推荐习惯

提交前先看状态：

```powershell
git status
```

提交说明写清楚一点，例如：

```powershell
git commit -m "添加 vector 练习模板"
git commit -m "整理 string 练习函数"
git commit -m "修复 C++ 文件编码问题"
```

不要把编译生成的 `.exe`、临时文件、缓存文件提交到仓库里。

