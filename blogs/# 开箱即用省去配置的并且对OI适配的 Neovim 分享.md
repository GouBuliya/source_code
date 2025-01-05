# 开箱即用省去配置的并且对OI适配的 Neovim 分享

废话不多说上图：

![](https://raw.githubusercontent.com/GouBuliya/repository-of-photo/main/495df702-1451-4fb6-ae07-d6d256ec1421.png)

作为一个喜欢折腾的人，我想把我折腾两三天的成果和大家分享一下，如果有一些报错什么的可以来私信我（爱心）

先看一下配置表：

# Neovim 插件配置分享



## 插件列表

| 插件名称                              | 描述                                                         |
| ------------------------------------- | ------------------------------------------------------------ |
| **tanvirtin/monokai.nvim**            | 一个非常经典的 Monokai 颜色主题插件，帮助让代码的显示更加清晰、舒适，减少眼睛疲劳。 |
| **mhartington/formatter.nvim**        | 自动格式化插件，支持多种语言。特别为 C++ 配置了 clang-format 来统一代码风格，使代码更加整洁易读。 |
| **xeluxee/competitest.nvim**          | 专为竞赛编程设计的插件，提供了浮动窗口、编译、运行、测试用例管理等功能，非常适合进行编程比赛时使用。 |
| **williamboman/mason.nvim**           | 一个自动安装和管理外部工具的插件，能够自动配置 LSP、诊断工具等，非常方便。 |
| **williamboman/mason-lspconfig.nvim** | 结合 mason.nvim 和 nvim-lspconfig，简化 LSP 配置的插件，可以快速设置语言服务器。 |
| **neovim/nvim-lspconfig**             | 提供 LSP（语言服务器协议）支持，让 Neovim 成为一个强大的开发环境，自动补全、错误检查都能轻松实现。 |
| **onsails/lspkind.nvim**              | 为 LSP 提供图标支持，使补全列表更加直观、易懂，让你一眼就能区分不同类型的补全内容。 |
| **hrsh7th/nvim-cmp**                  | 一个非常强大的自动补全插件，支持多种补全源，可以提高编码速度，减少重复输入。 |
| **hrsh7th/cmp-nvim-lsp**              | 结合 nvim-cmp 和 LSP 的补全源插件，提供 LSP 的智能补全。   |
| **hrsh7th/cmp-buffer**                | 支持从当前编辑的缓冲区（文件）中进行补全，帮助你快速插入已写的内容。 |
| **hrsh7th/cmp-path**                  | 提供路径补全，适用于文件路径、命令等场景。                   |
| **hrsh7th/cmp-cmdline**               | 为命令行模式提供补全功能，提高你在命令行下的效率。           |
| **L3MON4D3/LuaSnip**                  | 一个代码片段插件，可以快速插入常用的代码片段，减少重复编码，提高效率。 |
| **gen740/SmoothCursor.nvim**          | 提供平滑的光标效果，使光标移动更加流畅，增强用户体验。       |
| **nvim-treesitter/nvim-treesitter**   | 一个语法高亮插件，通过增量解析提升 Neovim 的语法分析能力，让代码更加易于阅读。 |
| **folke/noice.nvim**                  | 通过优化通知和消息显示，提升 Neovim 的用户体验，使通知更加清晰、简洁。 |
| **nvim-lualine/lualine.nvim**         | 自定义状态栏插件，支持丰富的配置选项，能够显示 Git 状态、文件信息等，让你的 Neovim 更加个性化。 |
| **SmiteshP/nvim-navic**               | 提供 LSP 导航功能，帮助你查看当前代码的位置和结构，快速跳转到函数、变量等。 |
| **windwp/nvim-autopairs**             | 自动补全配对符号（如括号、引号等），减少手动输入，提高编程效率。 |
| **nvim-tree/nvim-tree.lua**           | 一个非常好用的文件管理插件，提供树形结构的文件浏览界面，让你在 Neovim 中更轻松地管理文件。 |
| **romgrk/barbar.nvim**                | 标签栏插件，能够提供多标签页管理，方便你在多个文件间快速切换。 |
| **nvim-tree/nvim-web-devicons**       | 为文件浏览插件 nvim-tree 提供图标支持，让文件类型一目了然。 |
| **glepnir/dashboard-nvim**            | Neovim 的启动页插件，支持自定义启动界面，增加你的 Neovim 启动时的体验感。 |

## 插件配置介绍

### 1. 颜色方案([主题](https://github.com/tanvirtin/monokai.nvim))
- 我使用了 monokai.nvim 这个主题，它是一个非常经典且受欢迎的配色方案.当然你可以自己换一个

### 2. 自动格式化（[formatter](https://github.com/mhartington/formatter.nvim))
- formatter.nvim 插自动格式化代码，特别是 C++ 代码。我使用了 clang-format 来统一代码风格，这样可以让代码更整洁、易读。强迫症狂喜！对于不熟悉代码风格的同学，这个插件可以帮助你避免手动调整缩进和格式的问题。
- 记得安装 clang-format

```bush
sudo apt update
sudo apt install clang-format
clang-format --version

```



### 3. 竞赛编程插件([competitest](https://github.com/xeluxee/competitest.nvim))
- competitest.nvim 插件专为竞赛编程设计，它支持浮动窗口、编译、运行等功能，并且有测试用例管理功能，非常适合用来在编程竞赛中进行代码编写、调试和测试。这个插件让你可以高效地管理代码、编译环境和测试文件。（超级好用建议看官方的[README](https://github.com/xeluxee/competitest.nvim)

### 4. 语言服务器（LSP）和自动补全([mason](https://github.com/williamboman/mason.nvim),[lsp](nvim-lspconfig),[cmp](https://github.com/hrsh7th/nvim-cmp),[snip](https://github.com/L3MON4D3/LuaSnip))
- 我通过 mason.nvim  和 nvim-lspconfig  配置了 LSP（语言服务器协议），这使得我们可以享受~~非常优质的~~代码补全、错误提示和跳转功能，极大提高了编码效率（？）。通过 nvim-cmp  插件，可以轻松获得智能补全功能，而 LuaSnip 插件则提供了代码片段支持，帮助快速插入常用的代码结构，减少重复输入。

### 5. 状态栏与导航([lualine](https://github.com/nvim-lualine/lualine.nvim),[navic](https://github.com/SmiteshP/nvim-navic))
- lualine.nvim 插件配置了一个漂亮且实用的状态栏，可以显示 Git 状态、文件信息等，增加了 code 的可视化效果。而 nvim-navic 插件提供了 LSP 导航功能，帮助快速查看当前代码的位置和结构。

### 6. 文件浏览与管理([tree](https://github.com/nvim-tree/nvim-tree.lua),[barbar](https://github.com/romgrk/barbar.nvim))
- nvim-tree.lua 插件是用于文件浏览的工具，它提供了一个树形结构的文件浏览器，方便我在项目中快速找到文件。同时，barbar.nvim 插件能够管理多个标签页，在不同文件之间轻松切换。（有点像 vscode，文件树可以通过 alt+m 打开

### 7. 其他插件([自动括号补全](https://github.com/windwp/nvim-autopairs),[平滑移动](https://github.com/gen740/SmoothCursor.nvim),[更好看的通知](https://github.com/folke/noice.nvim))
-  nvim-autopairs 插件能够自动补全括号、引号等符。 SmoothCursor.nvim 插件则提供了更流畅的光标效果，增强了编码时的舒适感，赛博感拉满（。最后， noice.nvim  插件则优化了 Neovim 中的通知显示，使得提示信息更简洁、清晰（这玩意有点激进而且 bug 有点多可以选择性开）。

---

然后就是客户端啦！（当然你可以选择用终端因为[终端也可以很好看](https://www.luogu.com.cn/article/vmszp6zp)！)

我是用的neovide，一个大佬用rust写的客户端，我觉得他那个光标超级帅（这个可以在配置文件里关掉）

#### .1 使用 apt 安装

在某些 Linux 发行版中，你可以通过包管理器直接安装 Neovide。如果你使用的是 Ubuntu 或其他基于 Debian 的发行版，可以尝试以下方法：

```
sudo apt update
sudo apt install neovide
```

不过，官方的 Neovide 版本更新较慢，建议使用下面的方法来获取最新版本。

#### 1.2 使用 snap 安装

你也可以使用 snap 来安装 Neovide。运行以下命令：

```

sudo snap install neovide --classic
```

#### 之后呢就是配置 neovide

大家可以直接使用我的配置，也可以自己修改。（[官方README](https://neovide.dev/configuration.html)）

最后的最后挂上我的[配置仓库](https://github.com/GouBuliya/neovim_config)大家可以直接clone到 ~/.config/nvim 里面使用就可以了