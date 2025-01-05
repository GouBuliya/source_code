# 如何使用GitHub 搭建一个属于自己的大容量图床

想必大家在写题解和其他文章的时候都有图床的需求，但是免费的图床一般来说都会一段时间删数据。~~对还没有经济能力的oier非常不友好~~，但是世界上最大的开源社区网站 [Github](github.com) 就能完美解决我们的需求。

### 1. 创建 [Github](github.com) 仓库

首先，创建一个新的 [Github](github.com) 仓库来存放图片。你可以选择将仓库设为公开或私有（私有仓库需要进行认证）。

1. 登录到[Github](github.com])，点击右上角的 `+` > `New repository`。
2. 创建一个新的仓库，例如命名为 `my-image-repo`，并选择是否公开。
3. 创建仓库后，记下仓库的 URL，例如 `https://github.com/username/my-image-repo.git`。

### 2. 配置 [PicGo](https://picgo.github.io/PicGo-Doc/zh/guide/)

[PicGo](https://picgo.github.io/PicGo-Doc/zh/guide/) 是一个图床工具，可以通过插件将图片上传到不同的图床。要将 [PicGo](https://picgo.github.io/PicGo-Doc/zh/guide/) 配置为将图片上传到 GitHub，你需要安装[PicGo ](https://picgo.github.io/PicGo-Doc/zh/guide/) 并进行配置。

PS：不是广告，但是这个软件赋能 GitHub 后当图床真的超级好用

#### 安装 [PicGo](https://picgo.github.io/PicGo-Doc/zh/guide/)

1. 访问 [PicGo](https://picgo.github.io/PicGo-Doc/zh/guide/)官网 下载并安装 PicGo 客户端。
2. 打开[PicGo](https://picgo.github.io/PicGo-Doc/zh/guide/) 客户端。

#### 配置 GitHub 作为图床

1. 在  [PicGo ](https://picgo.github.io/PicGo-Doc/zh/guide/)客户端中，点击左侧的  `Settings`（设置）按钮，进入设置页面。

2. 在设置页面，选择 `Upload` 标签页。

3. 在上传配置中，点击 `Add` 按钮，选择 GitHub 作为上传方式（如果没有此选项，可以手动添加一个自定义上传方式）。
   - 在配置项中，选择 `GitHub`（如果没有默认选项，选择 `Custom` 来自定义配置）。
   
4. 填写以下参数：
   - **Access Token**：你需要一个 GitHub Personal Access Token。可以通过以下步骤生成：
     1. 访问 [GitHub Personal Access Tokens 页面](https://github.com/settings/tokens)。
     2. 点击 `Generate new token`，选择 `repo` 权限，然后生成一个新的 token。
     3. 复制生成的 token。
     
   - **Repository**：填写你创建的 GitHub 仓库名称，例如 `username/my-image-repo`。
   
   - **Branch**：通常选择 `main` 分支，或者其他你希望图片上传到的分支。
   
   - **Folder**：填写图片上传的路径，例如 `images/`，即图片会上传到仓库的 `images/` 文件夹中。
   
   - **Commit Message**：你可以自定义每次提交的消息，例如 `Upload image by PicGo`。
   
   - **GitHub Pages URL**（可选）：如果你想将图片公开，可以配置 GitHub Pages 的 URL。默认情况下，GitHub Pages 会根据仓库的名称生成页面。例如，如果你创建的仓库是 `my-image-repo`，GitHub Pages 的 URL 可能是
   
     ```
     https://username.github.io/my-image-repo/
     ```
   
     

#### 配置完成后保存设置。

### 3. 上传图片

配置完成后，你可以直接通过 PicGo 上传图片：

1. 在 PicGo 客户端中，点击 `Drag & Drop` 区域或直接将图片拖拽到 PicGo 中。
2. PicGo 会自动上传图片到你的 GitHub 仓库，并显示上传后的链接。

### 4. 使用上传的图片

一旦图片上传完成，PicGo 会返回图片的 URL。你可以将该 URL 用于 Markdown 或其他地方。例如，如果你将图片上传到 `images/` 文件夹，PicGo 会提供类似以下格式的链接：

```markdown

![Image](https://github.com/username/my-image-repo/raw/main/images/your_image.png)
```

将该 URL 放入你的 Markdown 文件或其他文档中即可展示上传的图片。

### 5. 配置 GitHub Pages

如果你想将图片通过 GitHub Pages 公开展示，可以启用 GitHub Pages：

1. 在 GitHub 仓库页面，点击 `Settings`。

2. 滚动到 `Pages` 部分，选择发布来源（通常选择 `main` 分支），然后点击 `Save`。

3. 这样，你的图片就可以通过 GitHub Pages 公开访问，URL 通常为

   ```markdown
     https://username.github.io/my-image-repo/images/your_image.png
   
   ```

   非常地好用！
