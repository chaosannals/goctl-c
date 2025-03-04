package main

import (
	"fmt"
	"os"
	"runtime"

	"github.com/chaosannals/goctl-c/action"
	"github.com/urfave/cli/v2"
)

var (
	version  = "20250207"
	commands = []*cli.Command{
		{
			Name:   "c",
			Usage:  "generates http client for c",
			Action: action.C,
			Flags:  []cli.Flag{},
		},
	}
)

func main() {
	app := cli.NewApp()
	app.Usage = "a plugin of goctl to generate http client code for c."
	app.Version = fmt.Sprintf("%s %s/%s", version, runtime.GOOS, runtime.GOARCH)
	app.Commands = commands
	if err := app.Run(os.Args); err != nil {
		fmt.Printf("goctl-c: %+v\n", err)
	}
}
