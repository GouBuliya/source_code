# 如何让自己的Ubuntu终端变得好看~~高端大气上档次~~，好用，实用

废话不多说上效果图：![image-20241223044813134]![](https://raw.githubusercontent.com/GouBuliya/repository-of-photo/main/a497da1c-c821-4bdc-b53d-96bf2e96870b.png)

还有自动补全

![image-20241223044909654]![](https://raw.githubusercontent.com/GouBuliya/repository-of-photo/main/54762abf-56eb-4ea3-bca0-7a5d719e9c43.png)
## 1. 第一步安装和配置 `zsh`

zsh 是一个功能强大的 shell，比 bash 提供了更多的功能和自定义选项。首先，我们需要安装 zsh 并将其设置为默认 shell。

### 安装 zsh

打开终端并执行以下命令来安装 zsh：

```
sudo apt update
sudo apt install zsh
```

### 设置 zsh 为默认 shell

安装完成后，使用以下命令将 zsh 设置为默认 shell：

```

chsh -s $(which zsh)
```

此时，你需要注销并重新登录，或者重新启动终端，以使更改生效。

运行

```
reboot
```

即可

## 2. 安装和配置 Oh My Zsh

Oh My Zsh 是一个管理 zsh 配置的框架，提供了丰富的插件和主题，能够帮助我们快速定制一个高效的终端环境。

我也不知道他为啥名字这么奇特（

### 安装 Oh My Zsh

通过以下命令安装 Oh My Zsh：

```

sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"
```

如果你发现 curl 指令太慢或者根本连接不上可以试试 Github 克隆指令

```bush
git clone https://github.com/ohmyzsh/ohmyzsh.git ~/.oh-my-zsh
```

如果还是不行你可以看看 [这篇文章](https://www.luogu.com.cn/article/l7ehv9sw)来使用 ssh

```bush
git clone git@github.com:ohmyzsh/ohmyzsh.git ~/.oh-my-zsh
```



安装完成后， Oh My Zsh 会自动将 zsh 设置为默认 shell。如果没有生效，可以手动设置。

### 配置 Oh My Zsh

Oh My Zsh 提供了许多插件和主题，可以通过修改 ~/.zshrc 文件来启用它们。编辑 ~/.zshrc 文件,这里我使用 vim（ vim 小白不建议使用 vim 别不听劝（）：

```bush
vim ~/.zshrc
```

### 启用插件

在 ~/.zshrc 文件中，你可以启用许多插件。比如，启用 git 插件：

```
plugins=(git)
```

### 设置 zsh 主题为 powerlevel10k

Oh My Zsh 支持许多主题，推荐使用 powerlevel10k 主题，它提供了高度可定制的提示符，支持丰富的图标和配色方案。

1. 克隆 powerlevel10k 主题：

   ```
   
   git clone --depth=1 https://github.com/romkatv/powerlevel10k.git ${ZSH_CUSTOM:-~/.oh-my-zsh/custom}/themes/powerlevel10k
   
   
   #同样的你也可以用ssh，这里我就不复制连接了（
   ```

2. 在 ~/.zshrc 文件中设置 ZSH_THEME 为 powerlevel10k/powerlevel10k：

   ```
   
   ZSH_THEME="powerlevel10k/powerlevel10k"
   ```

3. 保存并退出，然后重新加载配置：

   ```
   source ~/.zshrc
   ```

## 3. 安装 Nerd Fonts 字体支持

powerlevel10k 主题需要支持图标的字体才能正确显示美观的提示符。我们可以通过安装 **Nerd Fonts** 来获得这些字体。

### 安装 Nerd Fonts

```

sudo apt install fonts-firacode
```

安装完成后，打开终端设置，选择 FiraCode 字体（或者你喜欢的任何支持图标的字体）来提升终端外观。

## 4. 配置 powerlevel10k 主题

第一次启动终端时，powerlevel10k 主题会自动弹出配置向导，帮助你定制终端提示符的外观。按照提示选择你喜欢的配色、字体和功能，完成配置。

## 5. 安装和配置 Tabby 终端模拟器

Tabby（之前叫做 **Terminus**）是一个功能强大的终端模拟器，支持多个标签页、主题、插件和高度定制化，非常适合开发者使用。~~主页粘贴的话就是官方~~

### 安装 Tabby

1. **通过 .deb 包安装：**

   访问 [Tabby 官方下载页面](https://tabby.sh/)，下载适用于 Ubuntu 的 .deb 安装包。然后在终端中执行：

   ```
   sudo dpkg -i tabby-<version>-x64.deb
   sudo apt --fix-broken install
   ```

2. **通过 Snap 安装：**

   如果你使用 Snap，也可以直接通过以下命令安装：

   ```
   
   sudo snap install tabby --classic
   ```

3. **通过 APT 安装：**

   如果你添加了 Tabby 的 APT 仓库，可以直接使用以下命令安装：

   ```
   
   sudo apt install tabby
   ```

### 设置默认 Shell 为 zsh

打开 Tabby，进入 **Settings** > **Profiles** > **Default Profile**，在 **Command** 部分设置为 zsh，以便每次启动 Tabby 时使用 zsh 作为默认 shell。

### 配置字体和主题
Tabby 提供了丰富的主题和外观自定义选项，你可以在 **Settings** > **Appearance** 中选择或者下载新的主题。为了与 powerlevel10k 配合，你需要选择支持图标的字体，如 FiraCode 或 Hack`。

### 启用标签页

Tabby 是基于标签页的终端，支持多个标签同时运行。你可以使用快捷键来创建和切换标签：

- Ctrl + Shift + T：新建标签页
- Ctrl + Shift + W：关闭标签页
- Ctrl + Tab：切换到下一个标签页
- Ctrl + Shift + Tab：切换到上一个标签页

## 6. 安装其他插件

### 安装 zsh-autosuggestions

zsh-autosuggestions 是一个非常实用的插件，能够在你输入命令时提供自动补全建议。

```

git clone https://github.com/zsh-users/zsh-autosuggestions ~/.zsh/zsh-autosuggestions
```

然后在 ~/.zshrc 中启用：

```

plugins=(zsh-autosuggestions)
```

### 安装 zsh-syntax-highlighting

zsh-syntax-highlighting 会为命令的语法提供高亮显示，帮助你快速识别错误。

```

git clone https://github.com/zsh-users/zsh-syntax-highlighting.git ~/.zsh/zsh-syntax-highlighting
```

在 ~/.zshrc 中启用：

```

plugins=(zsh-syntax-highlighting)
```

### 安装 fzf

fzf 是一个模糊查找工具，可以帮助你快速查找历史命令、文件等。

```

sudo apt install fzf
```

并在 ~/.zshrc 中启用 fzf 插件：

```

plugins=(fzf)
```

## 后续我会补充更多好用的插件，以及tabby的背景可以通过插件自定义，大家可以设置成自己喜欢的照片！