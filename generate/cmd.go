package generate

import (
	"fmt"

	"github.com/gookit/color"
	"github.com/zeromicro/go-zero/core/logx"
	"github.com/zeromicro/go-zero/tools/goctl/api/parser"
	"github.com/zeromicro/go-zero/tools/goctl/plugin"
	"github.com/zeromicro/go-zero/tools/goctl/util/pathx"
)

func CCommand(p *plugin.Plugin) error {
	api, err := parser.Parse(p.ApiFilePath)
	if err != nil {
		fmt.Println(color.Red.Render("Failed"))
		return err
	}
	AllTypes = api.Types
	logx.Must(pathx.MkdirIfNotExist(p.Dir))
	logx.Must(GenMessages(p.Dir, api))
	logx.Must(GenClient(p.Dir, api))

	fmt.Println(color.Green.Render("Done."))
	return nil
}
