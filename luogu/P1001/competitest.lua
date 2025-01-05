
local competitest = require("competitest")

competitest.setup({
    local_config_file_name = ".competitest.lua",
    floating_border = "rounded",
    picker_ui = {
        width = 0.2,
        height = 0.3,
        mappings = {
            focus_next = { "j", "<down>", "<Tab>" },
            focus_prev = { "k", "<up>", "<S-Tab>" },
            close = { "<esc>", "<C-c>", "q", "Q" },
            submit = { "<cr>" },
        },
    },
    -- 其他配置根据需要添加
})
