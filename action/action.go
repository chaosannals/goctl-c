package action

import (
	"github.com/chaosannals/goctl-c/generate"
	"github.com/urfave/cli/v2"
	"github.com/zeromicro/go-zero/tools/goctl/plugin"
)

func C(ctx *cli.Context) error {
	plugin, err := plugin.NewPlugin()
	if err != nil {
		return err
	}

	return generate.CCommand(plugin)
}
