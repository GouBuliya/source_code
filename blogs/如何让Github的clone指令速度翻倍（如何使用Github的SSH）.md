 # 如何让 Github 的 clone 指令速度翻倍（如何使用 Github 的 SSH ）

如果你的 GitHub 的 clone 指令经常这样

![](https://raw.githubusercontent.com/GouBuliya/repository-of-photo/main/608c9d8c-9b83-4366-81fb-8caa31774bb0.png)

那么不妨试试 SSH 吧。

### 1. 生成 SSH 密钥对

如果你还没有 SSH 密钥对，可以通过以下步骤生成：

1. 打开终端，运行以下命令生成新的 SSH 密钥对（替换 `<your_email>` 为你 GitHub 账户的邮箱）：

   ```bush
   
   ssh-keygen -t rsa -b 4096 -C "<your_email>"
   ```

2. 你会被提示选择保存密钥的位置，默认路径是 `~/.ssh/id_rsa`，直接按回车即可使用默认位置。

3. 接下来，系统会提示你设置一个密码保护密钥，可以选择设置一个密码（可以为空）。

### 2. 添加 SSH 密钥到 GitHub

1. **复制公钥：** 执行以下命令来复制公钥（默认为 `id_rsa.pub`）：

   ```bush
   
   cat ~/.ssh/id_rsa.pub
   ```

   然后复制输出的内容。

2. **登录 GitHub：** 登录到 [GitHub](https://github.com/) 账户。

3. **进入 SSH 密钥设置：** 进入 GitHub 页面右上角的 `Settings` > `SSH and GPG keys`。

4. **添加新 SSH 密钥：** 点击 `New SSH key`，并将你复制的公钥粘贴到 `Key` 字段中。为这个密钥设置一个合适的标题，最后点击 `Add SSH key`。

### 3. 测试 SSH 连接

确保 SSH 密钥配置成功，可以通过以下命令测试连接：

```bush

ssh -T git@github.com
```

第一次连接时，可能会提示你是否继续连接，输入 `yes`。

如果配置正确，你会看到类似以下的输出：

```bush

Hi <username>! You've successfully authenticated, but GitHub does not provide shell access.
```

### 4. 使用 SSH 克隆仓库

在 GitHub 上的仓库页面，点击 `Code` 按钮，选择 `SSH`，然后复制 SSH 地址。例如：

```bush

git@github.com:username/repository.git
```

你可以使用以下命令克隆仓库：

```bush

git clone git@github.com:username/repository.git
```

### 5. 配置 Git 使用 SSH

如果你使用 HTTPS 链接来操作 GitHub，但想使用 SSH，首先确保你已经将 SSH 密钥正确设置，然后可以通过以下命令修改仓库的远程 URL：

```bush

git remote set-url origin git@github.com:username/repository.git
```

这样，之后的 `git push`、`git pull` 等操作就会通过 SSH 进行，而不需要每次输入用户名和密码。

接下来你就可以愉快的用 SSH clone了！！

记得每次复制 github 的这个



![](https://raw.githubusercontent.com/GouBuliya/repository-of-photo/main/3f048eb1-8f54-43f2-a151-e831fbe18392.png)



每次正常的使用 clone 指令就可以了！

![](https://raw.githubusercontent.com/GouBuliya/repository-of-photo/main/42bf5f0c-9a33-406f-b81d-6f13a59ddb80.png)