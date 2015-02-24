{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 7,
			"minor" : 0,
			"revision" : 0,
			"architecture" : "x64",
			"modernui" : 1
		}
,
		"rect" : [ 742.0, 97.0, 874.0, 892.0 ],
		"bglocked" : 0,
		"openinpresentation" : 0,
		"default_fontsize" : 12.0,
		"default_fontface" : 0,
		"default_fontname" : "Arial",
		"gridonopen" : 1,
		"gridsize" : [ 15.0, 15.0 ],
		"gridsnaponopen" : 1,
		"objectsnaponopen" : 1,
		"statusbarvisible" : 2,
		"toolbarvisible" : 1,
		"lefttoolbarpinned" : 0,
		"toptoolbarpinned" : 0,
		"righttoolbarpinned" : 0,
		"bottomtoolbarpinned" : 0,
		"toolbars_unpinned_last_save" : 0,
		"tallnewobj" : 0,
		"boxanimatetime" : 200,
		"enablehscroll" : 1,
		"enablevscroll" : 1,
		"devicewidth" : 0.0,
		"description" : "",
		"digest" : "",
		"tags" : "",
		"style" : "",
		"subpatcher_template" : "",
		"boxes" : [ 			{
				"box" : 				{
					"id" : "obj-12",
					"maxclass" : "ezdac~",
					"numinlets" : 2,
					"numoutlets" : 0,
					"patching_rect" : [ 44.0, 284.0, 45.0, 45.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-10",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "signal" ],
					"patching_rect" : [ 44.0, 236.0, 45.0, 22.0 ],
					"style" : "",
					"text" : "cycle~"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-8",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"patching_rect" : [ 78.0, 186.0, 29.5, 22.0 ],
					"style" : "",
					"text" : "* 5"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-2",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "float", "float", "float" ],
					"patching_rect" : [ 78.0, 121.0, 89.0, 22.0 ],
					"style" : "",
					"text" : "unpack 0. 0. 0."
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-40",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 15,
					"outlettype" : [ "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" ],
					"patching_rect" : [ 128.0, 71.0, 214.0, 22.0 ],
					"style" : "",
					"text" : "\"Kinect Interface Joint Outlets.maxpat\""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-39",
					"linecount" : 6,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 157.0, 346.0, 50.0, 91.0 ],
					"style" : "",
					"text" : "-134.058426 -498.785858 828.442139"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-37",
					"linecount" : 6,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 610.5, 328.0, 50.0, 91.0 ],
					"style" : "",
					"text" : "-252.932861 -649.773376 1140.557861"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-35",
					"maxclass" : "newobj",
					"numinlets" : 14,
					"numoutlets" : 0,
					"patching_rect" : [ 664.0, 766.0, 204.0, 22.0 ],
					"style" : "",
					"text" : "\"Kinect Interface Joint Inlets.maxpat\""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-31",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 787.0, 108.0, 60.0, 22.0 ],
					"style" : "",
					"text" : "loadbang"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-30",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 794.0, 144.0, 37.0, 22.0 ],
					"style" : "",
					"text" : "set 1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-28",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 329.0, 702.0, 24.0, 24.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 323.0, 687.0, 24.0, 24.0 ],
					"style" : "",
					"varname" : "toggle[14]"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-26",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 451.5, 702.0, 24.0, 24.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 438.5, 682.0, 24.0, 24.0 ],
					"style" : "",
					"varname" : "toggle[13]"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-24",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 438.0, 581.0, 24.0, 24.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 427.0, 569.0, 24.0, 24.0 ],
					"style" : "",
					"varname" : "toggle[12]"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-22",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 338.0, 602.0, 24.0, 24.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 330.0, 585.0, 24.0, 24.0 ],
					"style" : "",
					"varname" : "toggle[11]"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-20",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 431.0, 484.0, 24.0, 24.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 422.0, 473.0, 24.0, 24.0 ],
					"style" : "",
					"varname" : "toggle[10]"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-18",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 352.0, 488.0, 24.0, 24.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 346.0, 474.0, 24.0, 24.0 ],
					"style" : "",
					"varname" : "toggle[9]"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-16",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 256.0, 301.0, 24.0, 24.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 256.0, 301.0, 24.0, 24.0 ],
					"style" : "",
					"varname" : "toggle[8]"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-13",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 393.0, 413.0, 24.0, 24.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 383.0, 400.0, 24.0, 24.0 ],
					"style" : "",
					"varname" : "toggle[7]"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-11",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 526.0, 289.0, 24.0, 24.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 526.0, 289.0, 24.0, 24.0 ],
					"style" : "",
					"varname" : "toggle[6]"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-9",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 383.0, 177.0, 24.0, 24.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 377.0, 177.0, 24.0, 24.0 ],
					"style" : "",
					"varname" : "toggle[5]"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-7",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 389.0, 276.0, 24.0, 24.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 383.0, 276.0, 24.0, 24.0 ],
					"style" : "",
					"varname" : "toggle[4]"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-4",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 338.0, 295.0, 24.0, 24.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 338.0, 295.0, 24.0, 24.0 ],
					"style" : "",
					"varname" : "toggle[3]"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-1",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 451.5, 295.0, 24.0, 24.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 438.5, 289.0, 24.0, 24.0 ],
					"style" : "",
					"varname" : "toggle[2]"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-5",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 642.5, 295.0, 24.0, 24.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 623.5, 289.0, 24.0, 24.0 ],
					"style" : "",
					"varname" : "toggle[1]"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-3",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 170.0, 311.0, 24.0, 24.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 170.0, 311.0, 24.0, 24.0 ],
					"style" : "",
					"varname" : "toggle"
				}

			}
, 			{
				"box" : 				{
					"autofit" : 1,
					"data" : [ 50820, "png", "IBkSG0fBZn....PCIgDQRA..AvB..D.NHX....P353L9....DLmPIQEBHf.B7g.YHB..f.PRDEDU3wI68lGyssdWeee9877rVq8v6vY5dty2quW7PsMFWCXavJfaIPYHUsPZKQMJ0khZDsUjFUopnT9iJjJsJpRUMoozVE0hDgpRSokTP.ETPPBosFCFbvCTrw9ZeGN2y367dZsVOO+90+3Ys1u62848dFtPiqO28Wo2y9r2q4ouqeCe+86QLyL1fGYQxTbhCi7kYAgXJhYFkgBnEvCIcAJFd2PbwH3pgEGAGeHLbLTdQvWw7Bv4KvqsjRIJJFRT075VDb.Nwg.jRI7dO82hYlANAAI+cLbc++MXCdPfrgv5QaXvRxJHSZHRlzP.Pgl40TN1ghgnNjlEjtwKwq8Y+T7+0uwuN6tyk4Eeuei7N9l+vDd7qvBmmpAiQMAEG5JDVR25O37mYa1Oc6L6aaHr1fGNrgv5QbzSX0aUSRS36HSzjgWETwPCQfFnolvrC4m9+v+cY2BGe3umuepm0vK8I93b68Ofu4efePpdg2IostLsgJtvEt.kkkLXv.7NOtkaWCUUBNOppYxrNBqUs1aCc0F7vfMDVOhCcExJ.TSWYhFN7fGlyBj5IDe0Wget+1+Wx66o1hO3OzOLL5pPaBZNhewereLrQWlukefePd8vVLe31jRsLZzHFLX.gPfsFMhs2daFMZDdmeoqg.3bNPjMDVavaZ3t+yxF70xXY7ivP6imkks9w4EDeKJsb7IS4nW4lHeluHu1+3OIu++49AfsdNPtBL5ofseL9W7G8+.9xe5+PFb6CYjuXo6ksssb7wGysu8s4ZW6Z7pu5qxctycnM1BjcEbC1f+z.guZuCrA+SOXlgIFNmaIQVzZ40t9qyqeyC4hmLkp6b.O01WjxseLPFPRFfO3gTAtG6IYwISwESLdPE2pMh2mc4yr75sssk82ee.XznQTtUwY1dmIdZqY82FrA2OrwBqGwgHBpoHH3bNRoDBBlYb3QGxq9puJ6e66fqsEQLpd7KvBeh5uxWFlbBdeMLeentk89+72lq9bOIocJ4jloDBAJKKIDB3bNbNGgP9cfKVrfISlPcaCISytBJfXfCAGBxlfQrAOjXCg0i3PPNMKdHDiQLLRoD6s2d7Ju10Y1zZbHrfDGsy.dWezOD+r+r+jvK8wg3qA0eY3k+c3m7+1ebd9Ozam5KOfYZDUUZayxan+Omyg26ottlacqaQccMwXb49ypgLciqhavCK1Dz8Gww5AcuM1RHD3V25V7k9xeYv4w68jpWvngAZVbK1p8l7O4W7+Ntwez+Ddg216DyR7EdoOOuyO3Gfq7M8Q4IdGeab3rKPSbHtNq050aUUQwxfrGiQtvEt.u3K9h3bNJBE2k9r1PZsAOLXSLrdKBTKKsfhPAGexwb3gGB3nvWh3bfKwhjxQp.6Tvk+ltBO2668P6gMryE1gK+A+5Y1vQbvfSH0bG7owr0fqPL1rj3QUcY7rDQv68b7wGyMtwM34etmOKoBwkk2vl2StAuIvFBqGwQu0UqZIyAGb.GbvAT383SIZqaQUHTTx1CuH1vS3k2YFp6PlOpls1JkCXuUQQ5PtRkfSKPTARfyAlp3EglXDmKKGTm2S8rYr2d6wS7DOAgPXodrTUyxbXC1fGBr4NlGAQlbo6uUz7D.SlNgiN5HZaaovGX1rIDaqwEbXwDoEsLaQMyFzRyiWf811gCufww6.GEpQF3ntYFgfiIymQJkVts5IEW0ZqxxRRoDW6ZW6LwxpedWcecC1f6G1PX8HDNuG7UUWJVzXLxMu4MY97438dhZKi2cL9QdvqHNiwUUrcUECnflilAyS3h4kc3vJN4jiP7PcrkhxRjfeYFB6+aUxnhhB.3N24Nr2d6cl8u02W2PbsA2Orgv5QbrL9RlxjIYqq5IRRoDMoFfb7sZ01bV+ZU1pZGFJaQ.OoEMLtphlTMoPDKjP0HoXjf3Vtc5C1NvRhq9rGBvst0sX1rYmY+ZC1fGFrgv5QbjimjvrYy3N24NDiYwdtjrPOsrY7trHO0jmfbQZqKQhPQ.PaITAGwQT6mC0KnJoHnKkMQOwzp0NXTUTfPHv74yY5zoKcWbC1fGVrgv5QbzSLMYxD1au8V9a8RQnWdAwXDyDPBfTPQXKvJP7NDGD6rDavvRVzNiAUdbllE.pHKsnpecur7e5zkUrKX7ymOm111kYSbC1fGFrIKgeMNztfp2qGJHaszphEU0D25V2BfbuqR0r1qRQblh3cnIEuufTTP8dBAGlqkjnj.blCqwnHZ3aUZIhT.ttseuUUXFdQH0aAUGoUef3qaavWDv24J4Y5jCq4l3F2F2f0wFBq2Bf93Kk6CVblr4Ija4K8s9EAOXAvIjx+.FfhPv.uBjTLATQQDvT6bIW52d86Cm2z2fM3gAabI7QPblFlWmqY8kMSu6a.mwMt7Bnfj.TbREl02D9zSWuhRJkq6v6E5Wmqp0pyrsVa9V++uAav4gMDVeMNVsraV2cpUwRW13ThLAOh3AbYxJMsjHxy.jT1.bwYmZAlXTmVf4DDweeiC0YrlakXcsI9UavaFrgv5sHX03Dc1.d6VN8rEVYwcF7CQrA4.wubkXHtHwzB.CsaR2Kxm0m1pjpuQYJbcgntAaPO1PX8H.tWc.gUsromD3LCJD.XqdafhPlvxICfN2BktF.u4Uho4OvVIstPQW1S4Omfred6+avFrJ1PX8HLVUw48h3rG8DXKi2E9yTlLEtJ7REh1EDd.jHhqgnNGSz6Z6rJVmTr2xNUy8lq0I71XQ0F7ffMDVOBgy6A90cAq25l0m2U87CykiuEALMfndbn.IDWKpUCtbUJZ2CRlUC9e+1eSrq1f+jfMDVOB.mb2WFW0BpU6WU8V4zWzxpnfjIRLUvgGmIXIiAkiQzBDonKCgQLIQhVVDmCAHosK2d8wjpucICmMSk8DW8858drtfSOOB0MXCfMDVOxiUICVUFCqRJb1Xf469q.uqBS8KcWLKS0VRo5tfye2VKcWVtsB4UHDnnnXSy6aCdSiMDVuE.qq+J3t0DkXfu+6lCzB7txkyqYFhCRjn0ZQIgR6cIagdrdaiouSNLd732v.tuAav8CaHrdK.5qmuyy5Jnirw0GbbAvilB3cC5lgtXOYRmp4awrXVFDbuKh4dWE6ade6t6taZdeavaZr4tl2B.QDpppV98yX8yRIMnHhgXZdvUUCTEFhiHhU2Qv4.xwFq0pyjVXmarmVMf68w1ppphxhxyXU1FrAOLXCg0i3nm3X73w2ylmGXKU4tfGwFPYwXPRnVMYChbYBNmPJ0hJsmI6hqKkg0UV+t6tK.KGLW2PXsAOrXCg0aAfHBiFM5LDJqqzc.5S1nHdvxAcWbIR5htBYNWFONmij1rhagmuh1WMf+dumc1Ym++5C0M3Qbrgv5sHnppJmwttuelK7ctEp.ln4VVSxgW8HTfY4.1qcjSh.IqFjbOxxrSEj54oyp9NbZuaoIMsw5pM3ME1PX803P59CdiIK.nLTvViFikTb.dwgWDbVNP6lHjLinWQEEmlnzM.mM.wFPcaBwY3PQHRS6gH9ZDWDyR4QNGK2oGDISLVz039JJJXqs1hxxbVG8NOFJJo6JQ.aHx1f6E1PX8HN5C3s26YvfATVVhqezfVM5ChNliDFlSPwvgGOdBx.bRUWV8xYETrHwzLLpWw5J8tZ4L8woJDBLXvfyzYIr0FfW2fM3AAaHrdK.5IN1c2cosscoln5mVeetRTCOBnchLE2RgjlI1xV.kvnM0h4Nav06WeqixxR1ZqsNcdNGAmtAavCB1PX8HN5KQG.1ZqsnttdYPvgrabN5s1hb7rLGNIfHdbRYWGa3TwdJhQJUi3xk0ypRW37HrpppXvfA+Ski2M3Qargv5QHbdw.ZUBqhhB1YmcPUklll7xfdNsdFAQbHjU6tpmZMlJJlnjnAShnqD.80218E6bYYYWbqryXc0FKs1fGVrgv5QPrtjBVkH44dtmixxxtQIm9xl4zZ9K+aYAh5vSQXDl108FVRnojzEnV6YrrZU0zCm1cHVUzpK2GYSWGcCd3wlAgh2BfdBDu2yEu3EYxjIHRdrJL3E7hKG+JwQTIGGqjGbdJJFhN0giSsxBwHQD0xAc+d0L+bNWVREcAYWMcSl.2f2zXiEVOhiUIG5qquqbkqvku7kWNR5zaY0otF1M3SXABTgYNDUVw0OCjFRzhyeZ42rZaqY092dHDNWBsMDWavCK1PX8V.rZuSWDggCGxt6tKau81XlwhEKv68rXQyJs9EGlAA+.bx.RI6LAcGIQSbJpFWVbyq5VXOA33wioppBm3XQ8hkkky4gyp.+23e69g06TDaviNXCg0i3X09QU+3SH.iFMhm7IexyzapVszcbNGNyg2U108QO8VEKKrARo5yzX.gSakM8aqlllkSqnnHOOhC0NaWd3dWmi26iu0wFQn9nK1PX8HNdiZTegPfqbkqv16bABg.gPnirwioBdxeFBCPjvx0U+mlEoMVy5sWl0aaMsssr2d6wzYSw67nlRRS3D2CkvQueiLOarp5sFXCg0aQvppNu2hHmywku7kITVgprTaVqlsPmDfzYs9pu+YkRw6p0xzGGKHaQULF4F23FbqacKpapOSiDz3Mlj4OIjOaHudzEaHrdK.V+g2d20TUY73sQDg555b44zMBQqZei+KW7ylYzIr8kwwJFaPbm19XVc6rJAVuUVW+5WOOh4zksv2rGGq924UKhabI7QWrgv5Qbr5P60pOneltPJ9kkcS+zxCGWdJ7EYqhNy.EQtHm0XCEEEmIKghHKsTKFiK6znppr2d6wMt4MX9h4ca26Ogx8izoe61KR0MVV8nM1PX8HNVWE5KCndGozjISHkRKCHd+7zCmK.bVgnBfibqRteced818TJg26W59YLF4ke4WlabiaPSSyepnz8yypqU+8M3QKrgv5QXXvc06zW0Us4ymyAGb.M00Dbdjjla2Lpd53MnEPRdTSVNzzmGl5UPRDiK.wv4x0dXu0W4t2fPTAEGsoDlHDiQlOeNGd3grXwhky6Y+6dCwN8udx2UGQfV83r+7v4dx4+eBel8UwOuqSCOfmStqYyt6udtq+0l9CK1nz8uJiUsB3Mx8mUiKzc0+zW4pd1hkbC3SDI+nup3c4tsP1MrLlbxQbyabatyc1mf3vgRpskhh.IKAdH4DrVGiFrCm3KIZy.mj6TxZKsw4fjH01fyOBEAwk.AzXDHfJdLmGGFpkIsN7vCYx7ILppjKeoKRYYfwC2hgCGBhKWeh.hykOlDfdWYwm6ffV9HNebZKKd6UGiFMyvDvVUTFcDc4Sn4ui7vGOsSWcq8Bg0mgt8qUakzhHqbYSQIa4vCxmBFJ4pQ3Ac96O9Ouom59+d.ou+9mKmzyPnblwY2UVGxxyetyrbJmt78iF.xYV9NYvf6gpICsgv5qxXcRp2nLl8FNvMzO+NAo68VNfjFIkRTVLfXJRJcZbqZVTyAGdH6cv9DIRnnhBeAfRxLPDRlmnl6bCUgQbXaBbQFTMf1EQDIhRCsworUoOOBQiPpsty7GH3cTmRHpGQff3vbci.OIkEsM7pW60vRQpJFvEtvE3RW5xLZ71T3KwLH1QJI.pkHoI7t7s4l.p4vDAetfHQM8zyWNgnpfS5JLHAW+oOEPyDy2KOGeXCbe2yrmhtMnPdTcTr7m86B9GXpJGFo6A0y8Z4xaoye58j0tLwyxAkDVtO5V8alCQV42V8fc096+ZmWjkqsygT+g.aHr9pLNuAig0+syaX4ZYrZbR2aRSnVKz08DBtBBtrnNK7AJ74GT1e+83V6cGN43oDcfezHl21R8hinrn.uq.m3Hlb37CH10SrFGJwWNjoylgKTRJ0PqNmnEQsHs0SovOfJWElyHIQTqkBwm6uVlmBuf3TRlRqpDiJoNsdohv9GbL6e6CHDJY7tWfw6dAFMdKJJBTT3P7Avqj55WoF4.66bNv4wKBhvxf4qX35N+jWhLwkWDxUeTuKruIu1woVJrJdihyhAfXqrDtt+00YExCvmlzogsGr4GqypytOWe58MG6k2c02i9wghtb5md.j+r2H2DNLxjXrx71+0UsrJS3k+AOqRt+fGYpMDVeUFqOByz++ePdyt18tSCEGFhDv484aBLP0ry.KpqotcAymOm8NXeN33inMFAuCOE4a7DGNeAwTKIyiZkTVNhXn.uOPYsQyzob4psIPISalgKANRDkH9ACvQ.hJVrAKXjHQgu6gESwRdLWtA.BNzjQY4VjRIpai3MEukEa5suy9by8O.PX73QbgcGyN6tEUCKyhbkrvSKCATTzXLaokjim0pjIxYdrvxV5fj6EXctPtz6v09j2fee8qNq+HWeBED6T2Akt8kU66pq9M4d7oYmdbHl.x8d9OywT+NP2N95y2p688GymRDuBgrr12wcWVR45rbasFMzcY41oa+Gtvnugv5qQv5w5JGGjDIS6tILW9LVW3bjt2BVunkacq6vs26VLe9zrUGENFLr.QbTWmnLLfPw.PSnZMkEdZiNluXAK7JkUUjtC7TEWhvAk3ofFQXhBgqlXpNkhhA30VpjtRyw6vjDVJgfz4ZGnp.TPhDXAlMsEmKfO3yjsc5yx2e.nQpmb.6MYeN7lNJGLjw6bQ1cmKynQiHTn3LEbfycpsUBN7cZIqOlJ8v04niHmZ+v8KlQm2zAv+FzeutaRgSgeE6OLyPV+o9UgHfYmy54AywJYc+cst04xu5NyDOkbcEWEYUhrUc2yki805q+ykDxc5u+FEbrG.rgv5qxX0r3cupmtyyRL.BR1RqjkvKNPfXqw96uOGe7wL8jSHosXVhxA88kJETnUUpbUfZnwDHQ7NAmWvmTPanHlXq1B1s9Bb7ezWlW8KdMBRECFk34e2OIaOaAUimwBIPqLjJ+vLwoyvTCrDhTf3bDwgJfYJNSPLXzvg4Bn1LZ0HgdgnhKSdIBBJN0vpaYZSjSlrfa956g3cLXnmxRGCGLfgCGxfxJppFRQQQd3HKkxw2aEYcjrDlE6Tce3txn0p+c+edpiB6bIUna+mbRCjdKtr9KpbJIw8HVTxc+64Npw8OFVVWzyN6umVoibj+6zHssx8fqc.stqr8Kwcch5thEl6tOQ9lLCsaHr9pLVU2PvYIjtec0.USHgT9VvVX+IS3vCNgSN4DhoVfH0MyQ5jcfWETM+PSgujx7KuQsF79DFQ.kl4s3jJ1tPvZRTtXK9c+k+Rb4A6xG6O+eUJGsEu9m42m+G+o9efum+BWgm6CF30GtOsEWh15cwzRzjqy0s76fSTRRLTYNhCbZf.BZ6g3cf2Ap2H10kHjDflGvVKDAm2H3Jw4bzjfjZjhQZmt.Ytg6vi6xhnPQQtkLWUUw1auMgx7PLVnJfW7cVVYcVe3VlsKm7v8Ijst0rrydm+Eq9+SWJQr054pROgBOTeJ7fsb2q0ufbZV551oVl0u6x227UxybH0+coOZW5R2Fcqb5PWyhqyFWqGNH1F008UUrpBsWsGRsdYtrJ5KslTpkSlbHSmNkiO9DluHhl.y4y2Dow7H1rnT365K6QCKAAWUVR.lgQM3lQqNixJgjzRaplz7Cvc3qvget+HV7YuF+f+X+mBOy6BbkvMdc3k+b725uweU91+W6ed97a6n3YdVFU7zDbai4KoxUwvzPPqXgMjVQPrZ7NGU1PJDOAKqIrZslVhj74A8BeaHO1H5EblhmHhjyZnZNPJvbBlzo4qtySNKe9qOY4I6T02WTUwViFwnsGwVCGQYYIkg6tant9456ExWq5EGv4Xgi0keP4zeOO5Bk+dl53gWVEOnEN98VbtNbV1AUwrNlHEDM2Z+yQFEnKalqJdpNNZ6tR6vcerXq5NX2h5Wc87Pf6oEVmWFr9ZE7F8v98Zd6weZdLed5rZUxndWB6It5Iq5UG9pKWLFYwhELYxjr6dSmRrsl55ZbAAegGevgJFFA79JhwFbRd7ADQI3B3DgTJhn437nAkV2BRUGywti3Ny9Jbb6qicvA7BGWvm+S+6y222wGCd52E3bPYA7zucXbfm5wu.Gey+PzKNlqW+ZrXgPQwXB9s4hkWkKHWkQ9Kiu7pTvP7wJjVfTMso.paLpY38B9BXdbABBUEE3CE3r9x9Ig4T7hBpRHj0ekIg7m8j3ZNVY9tyypp4RPBXwzEL+jYvsMBN+xA2UGmUI+2qWTbWpouOd1cDSpBpFomXRUPDaEQ05nnv241pmpgkK2O56XFqKiky69FiyISxcO82WT4q1GzV8EhqpUsHJdwxwrxIzSw0ROcZN5n9dxJ0xlk6yQ2KYJhy2EWPP0TWW4HgHK+UL5yFadaGE55HH54dt97dlAfvWKSJcuv40RUdilu6UK989s7mGgz8R.nqST0Wrwmmhz6WlSN4DN5niXxjILe9bZaOsjXhMo7PnkyHFaIpIhMMTNbDKl2rbDeNYQLEhtrEGRnEbIR5bRgIrWyKSK2g8m7JL2tEy4lLtHxbaDECa4oelmCpU3xWhIwHaEAFOFShDFDfxIbR7XptvXNbxqRgtMGbzeLWLbUJscvWbI1dvU4hCeb1dvkvqUjZKIRMwjCu.s0Q79BjjCwoDiMDjBDuGymE4nWDbhx75YTTTPq1hf+zfE6c4V9rjeHa4Cpch0TEA5Jl6XLlK56y479855+p+VJcNICYEg81S.YVyxeutVXxjYr5X5XtVNMBgRppJVRnMXvHBA2xuGBkYqlOmXY0SHJX3j.d+YszyrDXYg4ZlfRBenBAsK9Z4OSzaHU1kw.Nr1N2PcB3EvocIRofTmbE7hKqGN.KEwExZCz5rSSVIFYFFIxhZVVykwy6b8RBq9u70pjVOHDROH3dQZcuv5DMmWA3t57zWVL8SuuA3sp0UMMMLYxDlNcJSlLglllbs2YmZIQdYEFLphn1xhoMLb3PJbAJGZzlZXzPO0KV.t.d+3rxw8sjXNs1IDc6yb20335WlipeENYwMXPADSSY7HiJTNYXjK71Fyu6uxu.eWu2uSHFXHdvlC2303+muxqvS9Qd+PQKaOdKN43YLrHfy0.iElu3KSanBQFvIyBbiC8T4FyVkWkAUWkPwiyVitJFinjwjlmnvOll1VDwSSaKERI0RL+.FN7hQTL7RNiahzM.vZ47Alr7CWpQtqSXql0q9qSRtEQ6W6kNq6ixJec4KjVYx9kDRYMekmmdRKHlZyDW9NKaTCyN85usLFXYAd1FUh5BlLsFiDlJKChs3L7tBJJ8TDpvGDFNXLgBGUkCoZPAEgJBEcwkqOdfcIiYYeMqifvSnSzrB8BRMWJ78yiCsMg3.5uG1Ap.QxIQQ5lWemVuHls9xaUflu1ji8kxoUTPu135rmasJ4XcblRtR0bsCbdOX+0BDY+oEg0az55AoaAbul2yycyUmu917B.000b3gGxwGeLymOmEKVPQQwc0mz6WONmCkT9gR7TWWSQgGmChoFbdO3czDaIZIBUJRwblq6ygStNGt3kXp7Jn98nUOBWHgKF6HBRTnBEsvk1+B7I+u5yv+9+H+D7De+eLvEfW4Kve2+l+0we0C4Ru+c3KVcCZtfsrGXgO6RTYvQSpg1jhnNJcETXUXwBRsCoH7XT3tLiqtBU51b0cdVb5XL2.hsBBkDBCnoNkaWyVtnsqJJI1zf2xCIY3DhHjz93Fkgu6gTGZmTON0JXSxtu8fTdTuQ+tyENi678WyW0R59o6btbMathqm8kVjo4dLFlC0xwhTsHCpFksEIwRBLwksfRbVldYEBMmDHT3H3Kw4gc19BTT5opbHkUA7thkaGqKyl46Iyj8mdbtRLqVQWHZWxQRYgozY+EPSCkgRV54muiLt+7GcYL15lF8xFQNsjfNmyy5JtLJhbJg085hxWKiGTBsGFqqdybdZ83hjRIhwHSmNkSN4jkjT8iLy8c4f9tnvpVVc52Mb9bLPZZxjUVWluRIEI.IVPzeBDNhEbSNX1KwwytFKh6SMGhElf4ZAmPgqDmZ3Di11Z7RjgUNJ123YN5I3y+a9pTpOKzDX9IWmm78cEJdei4jKNmqq2jAWTvzZHoz1.gxAT21fuvgT14pPiBoHdQwSEw3HJcaSbgPgLDWcfsFeYBUWfctvSQYwigudK1ZwtX0EHkixY7zxDPZaNJKVvg5bDw5Tdsf4xcNUwxNFcVKe6dPnO6X2mpM37tVBb20H3ZjeKut2qjgUH27demUgmFCr7Hsc+.ARtZ.5+dev5yjrmFreyRmY489rbMV00wdWN89BJKCctZFnrZHgPfhAETVEnpKFmXclR0m.zrmzcVFEQnuH2ArDdq.RcjbdO3bDkSCAeQ+4fduTEPIsRtGu6ysqdN7trvZ0Y3qkfdeBZ2CqEXOHDW2KoGr95qmjoO6e8jTGbvAKCdty4VRL0aMU+7msZpXYOlpeaDiQZaSr6NWh82ee14BaQcyTPR3Jbbm8uI6d4Qj7mv9S9Jr+ruDyhuF0oagTMmPkBxBTWKKZpw6GRLBaULhTqtbeIHNFzLfGawU4x0OAOk97rkeKlpmvwaMmaryBd8z0Yhd.yi6SvOmPgf2URRiHRhjukjKlynm5QrVDpI6Hz.RQGEtAPqPUXHKVDIk7zFGvfpGmq5dV9m0+dXXytb8iVPiJbks1EYqKvdCtHS7UnNOQGnNeV9D8jVVmKgKk9zJAUuK3zAoWDoVm2IVmqT445z76e5zAImbi0BPd+1XoEvc2eF5UfeeeCS6rtR3LDTqmcQmKfYYqnWOKiqGT+9eue9WM3+muts.m3IYJIxDiUEELtb.iGLlAgJBUCvOzSXXdIBjIepPYb6LFjlvrW8U3narGCJFwEeg2NLbHKrDr0VzP1JzRKfOY43JJ43eE0Ds0MKOmsZFyWGiFMhgCG909DV8CUUqiG5hV8dDz8605Z0QV4y6j974yottloSmxrYynsscoaflYDBgyzVg6Il5mmPHbluCrLaR.rXVMCFTRnRXx78Y3NB29nWlK8jAtywuDuxM+brHcaL+LX0J1+K...H.jDQAQETiZ0fKgyCp1hpyQJBjJB3cUDOZAk9wjhAFW7XT4dBFFeBdtcdebY+SyrqOigC1BcfPbfxLYNSzCY57aieTM253WgjaBmL4N38yA4PLYJZnABdjP2PVepF0ZPIh38HoJJ7CnssMe7oI7TPaaEWZuwboOYhIegYLu5BTL3hbxquOi+.+Y3Wammmu33KSqAQGDcNh8wuRxVe46ITVdI9zWx02zAueBv7M5S2pVQcNYYz2EOqphRtvEt.WbmcoppJm4yTjf+rVJspEV8DRqST0aQkp4jTrJAW+7k6iYmR38FZQlJYQ95yVfIVlTwm.SErBOMhRjDUAgKE77XHry7Zt5gWiwe1ec1+S+I3It3Svz5HkW7w365e8ePF+g9ffCNHonlGoQocVCwE0rnIxrXCsssDaZxhocsfq2+LWeVduzktDW9xW9OkIrNiPyt6IclsyYl+UK1gGDrZ5ZkkJHd459AQ7kqZJeW5ZsNyT600ClqKUutSccvN6xGiwkiNLyVLeYrmZqaxitxI8LWLrNSqE74XNP1ErTJAZJSPom1UPiwF7hgy0kEFyPSIrnhnJi7dBNOGN8HFtswsO9kXwf83kl7GxqO4KxEerBpSGhTp3Jjboxz+1+XhBmm5XhTnh54v.cGFWbIFO7pryvmkA1yvX+SSQ6iQPGg0jE6XxKjrDNuBRKhugEwifQMrHc.I6DlL40XQ80oIsGySGQjVTmGyYDjHRnEMrfjVinYhabBduPfDooQtncYF7xN1+W504G8uz+Qv292MnA3O5qv+4+T+83i+je87Y29I4VgsXZw.vYjVdwxwREWKYUyepBrWozSrt.+1eeS+mq+6my8g4.aGWF3X5s.q+6phav.FMdLCFLB.ZRQf7KmjTLWZQqdu4Ju3ac4Mza48py6pee8WX1SHedKuYVNdV4nikcO0RYKR0tro5ykUUqXDrDaqFO8hY70cmavyu2KwGd7L99+W96FdlW.Tk+ve1+m32726Sx26O7Gi3ktDG5qn0OfPRf1NUcIBIourjry3Vd+9W+mylMCUU1YmcX2c28TcXsZVpdXHsztnr4T+oDPtUHn5RcaZY.3xZhIn8Wc0rqBqSrrtqZqTLoH5xhJ0DGZWliRZhfySJEOsbL5t366NAjzbpuM56IQob06SthymYSovITgml1FvUlOAZYMirXxQjRIlUu3TxoXjnlxJ50IXIPainoVJD2RxFy4IhQilu4vzDkRDm1fyh4RQo05TSctd4cZKdWjfnDzHEIksJFPHZTFU1+q7RbsW4U4282+SgULmW78tCMO9BJdAks1sgs2ZDKNLgJBIKKgOOJp0RRSX0iPzcHrXa1J73bwwu.6L5YYn+p3zswaaiuc.VJjy9VftZ1yVInrEf4oRpPWjH3dLPZY2sdGzN5.R1wrHtGSatCypOj4sGRTmh1LAsvvGfBIQwfBRBbzjSPqBbohs3Bupiuxm3l7s8c8CA+K7WD7k4Xj7AtLeO+qtfOw+M+z79+F9yvuyEd2brMDu1fmDIWBviqoH2Ra7cs8F02QZsRDk6c86zaZW8Fw69ssKgak.Xm5+En+dMx2j5FL.spj4AGlyg5KPI6tXvNU3pmmrXNuf4upUHmZg38e4Wcc.f3LLI0eTl2mkbbvbIAQyVoh3ykTEB60F4JsWmukKE3Fex+.99+a8eAb0qBgRndFume3eX9re4OOeweueWdwO32JUW5ondADBUD0ZLQWl7.myg2EVx638d7d+xX4VUUw3wi4hW7hboKcobsiddjTOHYMIi9F1g6zfy0868VLsLKHbZypXYzXNya7VIF.86GXKaytKUtrlVJpRu2SRScs3j79cv4W5VkpYS1cgvoDW9BhZh5NWOB9bbEDwkK2Cf4ymhb7bZZhLIFIhiIGMCoMgjVf2Y4D.KBh00OwIAlgqKXvAxjNEpAwHDOMaTlq6hEFkRKAIQgo3sHZa1r4lEyH1zflpYxw6gRKwTCSlLkWe+SnPK3UeoWk8tyQ7Q9n+Y4e6eneXJuPA+dexeI9G+6+qxUF937ruqc4Ut00XvEGywMSIHAz1bWcPSknMkD3JryvmlKt0yynpmhR6wwo6hztMNsJmAGQvS9l6tWw.jSDeZokEdLKrxsAJlaDUtcIIynp3oY2gywjITGOgYyOfow8335qSSyAzFOlzrH9RXmpgT6VfyFxkRi30l54a9a+6Jmhps2JqemfiugOz2Duqe5eV1e5InUSgxswDKG6FE7t7KpTbDc0cggx0UNJNPLL8dvG8f.KWD5KqMuktxjsLSpFfqX.R4.LefVQH48cJeGzUrvXcQoBfrZMtH2sGCtf6Lyu0aUX+7kGkPNy5Xkc9bFeIshknBHdbNe2ivJZJAH37EnNGpOfbyav27a+4gm3ooVDHLhJCn8D9t+99d4W5W8+CdOeXGMZAUtRZVjk2AdAy4vI4WbzFicFYjnsscI40nQiX2c2kKcoKwvgCyB7049SdsDlqGqDZGSsy5CdP9B1o72faIQlzk1l7InbpYW8FmSUFagSvzzxL+38E3ysXIhICmHT5xo1tuiahYj6ASF3KxpoUjr.DIWJGDSL8jobxjivIAlsnlSlufEZDhsLbdMiGVwjfwbLJ7CvHQoKRS6BDwkKbgTh.FUNkJIRH0fK0lI1HQgYPrFI1fUOGodAsyNg3ISHsXF0SOlEMMTuXFsymfUWiKlva41U7r5YLrpfYSOlAAAmZ73C1gJ+Hd4W4U4a8O2eId2ereD3Idafk3a5a5ih6m+43S968yviOZL6bkJZGEPZ8T5F.ph0LhgkOK6ryKxEJeNpbWlpv13zwHow3sRDpPbPJ0hitnVaotGL74fZ6L7Vr6deoSdf8UjuC0JvR4TrK1NjZay8HKKxEqLtz3FZ3PlUeGZrIrnYON7vWhYStMGKMrSUAQDt1suIxnDLLgZyHEi3al.hwMesayVO82HW7BkbM2QYEVOn.mBnQhRMpCv0cmnEQLoi7M+hp2rAAIGBAGzo2Ijdq1skoTyRNRZ.ep.07ztjvIeNMe9boOQm9W+bYqLMasXtHB5Rgq14x2R2ZO0Br6EirjTLwioqTgelqq7mzbMzXfqvg1LGeYIdG.AL0CwE3KqH3ApMP7by81OWdXlPbdCkCGxBsA+vBhEYI1XI.KQoysbbwDfppJFNbXWyb7RKEVMzkDn0Mwb0Ou+vc5IdnOgxcmIzk0hTtSI1QU04udOADZW7fL5ph8r30jkMgCK+VFKGqgjZnVtQs4bBNIjq1e53oPPiJo1HMMMrXwAT21PTaooYASN4XH1R.ApiLpHfkxoOtxLtznQTe3QLpUgC2mgicTLpjllailpQz43jHdQHNeN5hFRMyHN6DlsXB5hIjleBol4jhKnY1TzlEnKlAs0TkhTYJEZjBUwgf2IriSy5exxVstrVq7JUdE1JfSMJCUL83igzbZt0bdOez+rvUdJnXDQSHzBefO72K+J+L+M4a3C7br8SdI9R24DhM6vvpKx19cXqseRFO9cwtCeABoKh1Th0.l5wIkjscJ6xpy0IwOI+YeQ21+l+dKUxOvrxCBRVRApJDiPRUT73binH3yjFwFpjcor7IvnlT4DdhwuCrpi410uL5QWmhq1v63C8L7+1+y+j7uxekebb9KQouBbI93+h+hbw2w6hWNk3jStMiuxikiCiVizJnQCuOWtLsobrIqzHdCRNMGdpyoOM8fhdqjLjynwqboBIjLApUJ8BUAAWYEa47D0rvW0jRgSXYSyyrGZy8tmslFt6LWtbe2rSETq4H48n3wafq6ESpXzFWPYoGc5LjfGpUBHjt3Svu5u1+67g+89D7LeiueX1rLe2suM+F+C904q+i7sxL5ZqPdG9pR.qaXeqAKYT5JwGpXznQr81ayVasU1suvYsiZUqJCqOgG5z7Kqjtc5NeKFX4zj12eE8zeco6hiKkENlikpK9TUF2ksk9hlbYXFx5us2JWkrN0VjRLaxbN9jbQ.2zD6BbYrq1oTZqOAWplQEd7oVnslsLgslZDVzfKYLRT9i+G9ayW3y8o40e0avEFMf2yydUdrKMDnF0Z4jE6ioMDZizVOifIfFykhf.EdghNkWm08Rt2J5HSHU3M7cb.p.Ne.wkvIZVDnXDMgXm.CKwwIKlwvhAHpil4f21lgECX6pifK+rfeDTN.0Rfe.7rWEmCpbUr+0ao7xu.O4Ed6ra0SwVgKw.4R3hiIdXAhj6KVdIfKDPz9gwKPbJhSIqL6t2XeW2e3Wokn2QpkGIKvDCmWHPNP84r1kcZzzrzC7ggXsNboQDbWgn9zLa9d7TiuL1icM9z23Wjm+CdUtwuzuE+F+3+H7c788W.qshOyu8mlet+geJt1W+2I29oebBJL7f6fHdBhGM4nrn.pa.Th97cKgtLslb8YJr3rYf4gDtylyprKMKO2XLuoE+7RplMhpAivUVAdWmnU6BH9JtD9vh62xrdLtNCAllP5DKp5xtoFLoSG54XKqBjlYDzB7ggTKAHJ7+8I07A+y8uD+W+e7eM92763iv69C+Qo916yO2e+edt7i+D70899.rewHZJqngFbZh37ELbTE6t0E4B6LjKe4GiAC1gbcVdZhl52+VWzn.4XX8FcR39E.9rUum0L0HYKcBcw7nu5lHE5Xy5pFbyxmPRmlsFqyjWmjGAVDmPz5hEkANOfknYwblexDVLcJ6s+swRJ9jQvDJl0vHoqmeqQJc4raDRsTnI70KX1QGvw29lb7gGwQGbDwiOg8t4M3K9xeIJ1Y.+k+q7iBuy2KL4H9C9u+mjeme4+A7AdGONaOPYXQD0ZHnFCBdLMlyzWQ.5zzRzHWVBNCIc5X4mXfyNsx0UmPcbANO38JAWtM95Ds6EAFssQJKKAD7EARpvfwin9vZF5K3feseYt3+FOEnMTJ0fugW527WfwOYIGhim4we+T7Tua7wKQgsKRZa75H7oJpbARVrKM5RNAIcw+HWeiBl46JeB.DDmfced.eoaNFnR1B47nbijszIkxBXLDnsolxhg3IPJJTHUrcYElulqczeH1kGxI5b959vOCsu7s4uyOy+IrXVIuvi+A3O+G6uHetm+CwW1uCfQU0.hsf3qvrrKDEclumCdbDmEO0i.QPne3M6gWVChkiJceI9B43StphwUxgFAe.WvmcON3ou+qX5cGv70y528C2qftu9xe1xPRozkyxdeUBHp0c7DI2TL7nIAWa.mTQMkDRyYm3Sy6HdKt7kZ4v+3OK+8+o+6Rq43i7c88v1uvKxwECXdQIysHgxJdxm3wY2pQbwKrCduf1NCW2nPdeB05EG85i.RqteKVFm6Ih6OgUVeF4C9BLDRV1sOukGUfaEvYdphEfAQe9lXuk6d.Re0oatN+u8cgn2HhwhTMKVLioSNhYGe.wISwVLiPajpjwtUEXSmQw7F1FA2jIDVzxh82iY6eGZO5DZO5XhGMkI27.1+0uI57FJCE3MCmjntYFQmR7EdF9N+a+2FduuWv7f0B6ec9G8S7Wmq75eJdtsThCTZHRTy0xVo.Rm6NsFDS4aRCNOAuCmlV9lr7IpbFWTxo1kP9sKNM+1eeJg2LDM21h0PIIIWlFhAWdztb7clfVWvgMAd8zV7s8uy+dvG4aAt3Hl7q7+B+Ze7edhuiDiewWjm7s88QS7wvZJwrJBUagQEtXUN9MtXWPpOsfcyucitL2TzcSUNqRYan5tlKmNZP2qv9SQ+aG8qTZJgkCdq8J8uppf11VZsNUZqARbaNjeGt9zOIGneYFWnr8DfosTTTfEuDO9vuUdhm8amaySwTc.V6bJCEX3I4bDa07KQVBWtM0zEyMsKCymlzm2bDVttX8bFZgUGEdbc0+YeVt6R4zxh0tyCk0C395OS9FIP0P2C8qtbqtr8Ifp+26Ivbtt5+KlqxgFmiTWHI7hgya4qukEDBkLxOFKAWbmKhSRLrLwEqfKnIXxIfT1EmsDr6XzfPCdh3HoJdySg3x8zLXMYMcVr5wy5M3xv5GfOrwwpe002JYoyreoKlF43V4Hs7FaPHgPBmpXo57M8l.QEl2PZxDN5f8YxrIDSMXZC9TjKiRQaKLcBK16.ZO5D16fCHd3wr316Q8stC6+xuL94yYPLRYRYfBkpfuMQg53Ejg3TgTZVNNMBT6pQG54YduuurkUitHDBvrovS9B7d919N3i+e1uF+y79uBGMaNggdbtbM9E6pHJSD7EE3J5LRI0qGFAgPN.otbFRZkbwMz.DUe24u.AQvGD7JjbFspiEJXEANYwTJKK4UlzhezNr6icUL+HR6eL+T+c9af+WXHSrivRGwi+M7jT+Di40mdStTRY5dS4YdhmloSSnoRZ0bFLEKgjkDc95szQFI8JyOjy1k45hiXd5l0U2abZ57O8Ngdc9b5CJYQPlmZL1r79qPvgFy2+UTlsnL1LC+nYLY5qygMuJEiTlklS8PGiuzHt4wS3Ji1g1hGmCpgJpoHknHn3kD0MQJJpPbNRsKP8c2OatrU5V1cGUxc+TYoKcu4DNZ+SIqRujOG08P2J5eJKx3lkssXkb2d3zNQZWLo5rH0jr2IcsvcxmwyAkuKrgzLexYddc8O0ndFBtd4CDj.k9.CGN.I3wFTQQUfpPAUAIWsBAAWnj.EPWtUIl0JXabAtfm4oJjKrEUhm73MRj1TKN7D0VJbELvEnI0RvUhZ4Xl4x0AN9UbMteeb05kc8JYIzKa.QxM++hhhkpMdUk61WlAKGFyEoqs5pD7YU0lhok8doppRZaawLEm2vUXXZVOQjpoc9I30VZmNg3jIDO7XbmLiho0HGOkpiOhhYywlOk4Gc.yty9bzgGwM+BeI70MHyZflHUEkfpnKZnrok283swmpfXtiVZoX2CMkYQE11fyx5rJRKRHPSpS.fw1NIHnmp8hjxti2BWK3hBiJGwhXDmBAWNM0lKWo99tDJnplKACSHpBQK+llFfVQHJNTuC0WRqTg3qHRCTVR41WD2fwPXKBiFRU0PBiGxVCqH5BjJJY6cuBMQE7BuuG6Bne9eK1a9mlsFMhZ+EHdwRVTprke.+w23Swa+w91oNoLuwSwvRLmRiUmUTdL2v7LTnqkDaVJ+fs0+fokkT.8uLxkCdnnjNiKUb13AI8Z6qSLtcBksOnMlIfuDUMBssTVYnUS410uDGpuBopCykBRAzFaXZpBWwkXqgOGWcv6hh4OAh3IV3oVhLyRHEdZ0VJh4HfFAvb4jrX4+uJYUwqVBmjs.9dZIkXrZs50qrbQ5zSWGAjy4PB8CBHcO2ncEnr1UsBo7zxVyZHRNnJ9NBz025Rm238ehk61p8DsA2c2Na5y5ly4X3vgK+shhhk+k6FrBU9gXBz1c+dPibZuT.Pktjmk2+TuApRgTBZNC8ILhZDWR.miR+.LKwXJyu3VfJwCVrqiu1Y+cmdMWualrJVuanD5Mozrbk12+IjUw8plT1SX0exI3KymV0bcAU58PaCUjfimRAJEZBbdhW60INaF91DsmbDGbmqS6IGSyw4XHM8F2hSt9MY90uEw8NBlMkxXhAXTjTJUX.BWYQjghmJUvoNZ0E388M9r.5gSvLM2FRviyKzp4vYmnKyH97aKJHPRUFWMf8lMguzm4yvG30eEXTAzlUbNSOfOwu0+HtvybUtEkDMEKLhFwXVLgUTPLoDqyC2UhjEImqbHhujhgaAECvMbKbUCXzfADFVQ4fJbEiILbW7kCgBGLnDav1z3JoVCnRV82RYfYwFRdOohJlfinZ3pbbclBuy2I68U9bjJmyvGqhCpOjZTF4q3vEeQdws9F3vC2iAUOc95q2Cj6XoFYKOjNM2jCBKcsV2NogjqchUtso+lpSsbp+8+m0DeANqyRKuWJGT2PmE.dJEk4y1CcmSXuS9JLQuAtA0DnDyDJGNf5EA1p3Ynx+LPbKzFOJQzfRx6v5B3dvkHD5RtSmK2AsWxxtNA9lOZCH4NKAf0MHEpVW5ejPVidt7ua3ysSl9bg2qgQGKcystsoqjpJnrrjTSpqADlsrv6b36HKxcUlzxyIcUyXNAUt7vQVuZvQfhUHdJKyidPaMZbtaptxustZ3eifYV2n7ce1R65bqKe+jfyJPXkQ8aIO.qoF3TI2tqQ6rN2xgFxxYOV5x3cuQrxJ243jy6Ni6OB8EaaccMSlLgISlbW9Nlu1H2kEV4.olcErULFzTySL+DZuwqxw27U3U+BeNZ1+Pd6W8owuPYx0tMKt9QL812hloGvhCOfscCwmLJMgqRNqKtTmLHLnrnDmAZLQpUozMLaAj45xtkGKkHkTJB4xjn.O41CVDKk0lhR17SITfBLWMHoDPohALjJ16ZWm+feh+Z79+K+uE77uKHY7U9e8uGepeiecdau3iw0dpGGUUhAGyCFiu3kI3GQQYEaMbaJGOlhAigxADCUzJE32ZaTe.ymCzppI5pfNDwSxBXcCZnISvDGNo.jhkwEKggTo3qDPUBpv3Qi4n4SQciHrkmAW5cSsqjq85+Qb0m+BzFOgiiGPXmE7Gu2uMeciuBgTSd.OU8cxPwg9+K68l8ikkccle+V689LbGh4bnxZj0Doonnl3flHo5VMkZ0RFsgs6FvFv9U+efggazvFvFvu4mLLL7.b+levBsksZnwVMUylhRjRhTTr3XwZtxpxrprpbHh3NbNm8du7C6y4bOwMirprXIQUQl2uD2Lh3Ndtmg0dM7s9VlP6umJFhs82kVOpR7qKhoqhsm.w1y.GT3j0dFBzaTSZaJ4TI0s.N7pRYVFMMoFx9MpdYpj2jplCYbokEMUndCERI5xR1Z6mlIxiiFc3oI0GbhAqOMHWyLADi1VNcZkaFMQvWsMWqRDMjxaZhZBok5SNQoqJxfQR+cZhsRZhZa5edhMYXuSD+LlLJxK5Sdb0xPJucYVJMVhQHz3I3SUeKcsTqbwzR3Ymy0+SiwvVasEVqk777dOiNMiQ8gQQmj4c2T0QALwVVrmNN5ay+VfzwGmPaJan2fJRMdqATGNsU29kNCucmCXR6mMIsK0DMIihwzhZhsmQlumfyZszzzv0u9040e8WuWVS5Z5vtlKdXrwctfZPvYLLe4RjLkoKlwM+FeM9tewu.O5G9w3m6S9I409teW9K9c+Wi7RuFOfVP9sT1SEzlioTDJUSaRqSb7I1tSouH+KWjxuS6Lx0oYz0+fXDTermrbojaBAIoVOQap5L3rznRhkwYYznJKBIFeOYTFUAOw8u.GVD4n5J9s9+7+ctwbv5x4b6Ll+K9u4+V7aMhatbN6LcDQmgik.jW.gbhpknZvqVpMYzXcDb4DrNVpJQqaPUg7XBCzgHWVZ0HwlZoGefLSFh3vGAw3nVaH2I30FBgkD7JAixrEA1876yaO6lryNOFW4FWgG5AeLt7U+9Tr6DFONmXYfW8M9N7g14mmF+N3jcfXAlHXybznsW7LLCnpkSGqul3o728YSsE5vbpzFdo1kL7jGCU0KXbthOaIGN60Xt+pTV.M9EH1bznEITxT6E3bieRJMWBgbH2PjFjtV9LjBdQiQBhO07tsdC0QcfXWMoz0XHd2+0lC19cEc+ZadkvHIusjjWDcuPSJRIHDayMV56qQauODJKKYx96RYYYugmxQivXouyMLFy.58j5ri9dAbsKu0ddwQ+DutCqWkMfa60CfmjhNj1K0onCIuQSy8xUJdABozrfkl1yYSNNjbQuaen1VXTLciHstE6573t8ZAt8uSuav0sZPmmV8FiZsX2QhqtjeMTcDTivxZOhI.0yvUeD+l+K9+f+Y+W9eEE+5+FPdAOx+HgG4W9eLey+Y+yI9s9dTHJlHXbEj4xXw7ksbqJUFc53fUH80zRxCIgjGJUg5zWXI4sBDw0F+ei1.kYLWBTYMDJcLSS+dEBMkkTdvATdwKvzKbQJO2dLd+cIa2soXu8I+bGvQ1T292b3LDmkhC1gm4vax3o6iw.2LLCiATmgPzfoXRqS7FhsWbFnshLZq7GqQzPaEyzbnk1FQDZpaRzZPZCIPLzjh..ersIgUOUdOA0y3wiootg49ZN241mYGcc1I2w9a8.by2ZDymMiKdv43su4bbhAuNiwaOkW4FeadrsmRgujLFgCM4kPj1Dp2Yj5jL+V5x2TKukLZb0U+pztLhgX6JysW9z+5Wo83oJxYhCnEgHDwCtFp7GAYGw0twKPbxsPYAwnGmMKE317R1q3gnT1mlkBRakMs4JpYIQhPKm6PCsgrAlXDC19Kth8WPkFEYwV0KeH4o6VTt678dMPWHwCstDEiMk1As0nXKG1LVCNmkbKbvd6yjIog.adVd58LFRINWjD8WFV99XnWir.v0pHswvp6eX9pBsMR8PVtu58a06yPiYqJH.Xkz4tRu1WkRKPW9KaDR8+n5REsHlgRFVah7CoyOThjQri4jRDgTUskTSpsphBlpVqYE8EN38Bb.TVVxktzkX73w7xu7K2abpqhBC6d5ta8cEtQXZwXpu4M4E91eS9Y9o9wn3W5yBtw3ylhKSfm7ixOwm4Wfm4a+sQapISJP8J0MUTjWfOFHD7zzwYjVciVMB9nGDKpUPsNVzHDcFjrbTmglfGiMiZQIXGy1W5731caFcvNTr2N7n6eNx1dKFs6d31aGzISXgSXlnrvZnN2wbminKGuXop8f21EagWiby7RBWXWN16HFZvMZLQsNchlyQPrf1VZYoMOIRZRLaDWRwFz1JIRJLLDoM7OHKKw.XzlD8BDCQIs9lM2PL3AwiwFIDhoN82H30.Mgzr0yRF02JiG5beX9NW8GPislsmNkYKOFWoAng293WhKs2Gl7vkNIcEBUsSFXCBoQfUTRmM2kWqaySpSvCqVCQcOqSLC8N4yQ010TkzBSQMhUiDsMP4Bd0q+rHkyYQ00YqIfSyIpFxYLSbO.Gr0iSocGBRFFWNVQIpMsWXlHpbZ.bjzsJSqh.jBwyfpcyouAUxSh21EyCqbdWnYCMjW0kE...B.IQTPTk05UOdfXHIgKFqkhrbFMZDau8T1d6sYznQm3yp2aISWvUIMMuyvRx39IWxHD6jX4NYLdvgABXsxItmz+eJYGpyyQVEhdep.ZeeSqC0drKlxymo87VjVu4ZCoiXZzr0MSE6zs8VGP6Snt1d9ReKQ14rC8Nz9dB8DGMKKic1YG1c2cw6Ss0xhEK50ooggH1E1XhZ2YLa1wLoRg4ML8RWD1pfnOfebFKidlt0DX+cYQLxExGgcoRtKinOPrtcLLIVbVgfIRinzXTpbJUVKUVgJqk4BX25.x1YG147mmr82kctzEws+9L5fCvLcBLdBAWFRVItxwbzhpjK5VCpMoHkAmBYFhNC0jnOPtaLM00XbZpxh1bh9XxyiFK4jgXyY9xivkONUd1nzpi2sjirOzTSqGVFbYEsglzter8hjNOWj1UX8ZpEFLFHDpw6UbhK87zHNifyjQUcEYYivVLl4KanHqDupDqOfhxGgISuDGwLlENh7oVLFGGdiYTlcL2X4qy3rGGsIfOT1dwyx9UIaOct0nqztJa5rptKAhC3tzJJsDS43P5NCc0ilLRs5mcLqNU4QOlX.JBbklWhqquDd4VTVjl3D4YSY1rE3hkLYzGhB2CC9rjo0VidB4HQRuOlTXZdMMNvDEJrYo7Pk5rqTyoaz9MSo0yxgUDeXU2BMgd0DQf9v1LtDMElLcDau8VryN6lJVULwgstE50XxfV2Ulw1HHLRRC261NZY51I4aExIxkrxICCr69V856Ndb5sazs+ba8lh.c58dxSaADWhk6sm2lSanv1jg6LrnZxiyHJNskhGwVgpjT0CSKPoX5zUoVdVFXU31uWLZ4FVR1hhBdpm5oPUs2fUmTOb7wGSSSCKWtr2iK0ZXYvy3hLbKxY+cOO+Ye4+s7O33YX1ZJtCeCJmLBN55bzkeUBNG2vaHarEQMzjYnBCZlknQZmKcB1sJX6yedFctcYuK9.TbvtL5fyQX7X15Ad.VnBjmQbbI2xXYgyxMrFzhRVpBl7RTbnQA6zcScAtIsJbSvC3aGEQJpylzO6ZPUKNaZU04KqIOaDFro1HIFQCQxxJnwWSlqHo81sgkdxDb1Uh+T3RhXNQ0zDI0lNRmmVzFpspHVaa8LCHFK4VGpZY4x4TTliSLDZ7HcpUQnAqojLSFdYIaO9IX1r2hrLOwXEgZCSFOBe8Lt1Medtv49njkuKUysXs4si.q.nRpWN0PKgJ61ZCIG.6ui17PQWC+5aetcIasKOEIbh7nDUDSGMATP7nzvxlqwgMuHyBuFR1bb1THppWHS2hB1m8m9DTXu.TkmzQcIh5STFHMQbVUMM.ztvUEZW7XkWXo6L0tQwnhUbIudZqZFZaJJDCY448bnJKKKMcoaGRq4ENxJbs8zZaH0VvX6N9m19zVtVkxOUmww1sqN5Mz68izuudnQngX86ui2iuSOm2YzteSgtVsS6ymbRoN5x8j1mPvUKvM3T6zBcBsupvoXLZcuueuA2vv6Flnthhzzycu81qupGcR.w74yY1rYLqZIgp4Tsrhc1YJW3QdDdjsuDOy+y+uxG++z+I3dfCf2bAy9+62g+3+k++xD0wqVnTt+try9WjoOvCvzG9RH6rCS1caJ1ZJ1ISvLdDjki2ZwarrzJbr3H5L7lFSq9cKoPihFPrDLssAglniQm2ApTmRgeH88K2YQj1P3zHhOI+Ll1ULPUrhkwaOAmMmxwivZyHy1p7mZjllpDg+z.KWtrmxGcpB5ICe3jJRIPaCAmzPKqMU0xtJ.E0Tq9fQHFffQnowiWgvxDO4jXpsirFCRzgnJpygxT1azGgCmcMtwrCIaTrMOG0j6BTu303sl883A1ZKjRKhO4oRRCG01bzrpD7oArPx.jQ6Noc35zoUmSc+RpvCzdRLRpcpRdojLzmxyU5yy3LogHQYEKiWiim+BnwqhoW.9BflgD2g815IXZ1ChtnDSLGUrobOIsd1YrzTmZgoPHfFST2HykgutN0hNYsEqIFZMNI3rVbEIp.zoR.EEEjmm26IU2Hue0wtUDYLQkltpiMH2PC9YZ90J8dYxp8P8iir0w60vjNMb28dzkn8A+YqQqtGw1mH9tPDa8.igdYKzKuNsvfomto8Ow1E1F9o9d86pDiQc8lLb3EXC2IOz8zXLMNk7VKGcy2lidyqP10dSF8puF+Q+V+ey0quNO4S8nbq23M3setWg+o+b+pbv9WfvCbQ7SmfjMhlhLNzYoN2RvZoBnACZVF3J.wPSrash1FFsqy1ay8fSyVM1vg9PuFtMOjEsoKDMsxTis+DzNMidHWVVenV1ggmPdh261eNzf0xkKARdPUUUw74yYwhEIkJUiIISdsWamzH2OAZfdcce9748BcVSS.Wqq7pQwaOjFyU4JG+04Zy9xTaecxKsn3Iz3IW2ix3SxG5A9knn4eObgcwDzVQUssfAZpQk6xKmo8DVSetrVq8ajDoKijxk2p6Oc7HMYmSSulflRqPSnNctkaFM1qxaU8M3Ut4WfX40PxcoYNn0AUSXKdRdr89EYGyOMl58SqbaThpOYHn0HYWpJbFSe+nEiQpqq6W3c73woVxp0XTYYI444mnB3cGGVOzvSCmFSreuHd.2scSxFrBN312YObG4o08zc2ufgfWY6sNG6u6dDenGFdzGkO6CeQtw0dcdkW9E4Q+neR9L+m+Xrzq7RRFr8VLuIMvHEigFZRrCNyRTDr1Bb4EjmUfw3Hy5vJItoj6boIDrMo20oYQWms5S5loz1jadeRwF5R5aGGyxxJ5IbW22u0wv9uZXOXMr3Cq68zpUdS2+1auc+qe6s29DZ6iOFRgb2JwxUUUrb4Rppp5098t4V3hEK.REHAnWryfXKgUakyEcG1cxixw0eepV9VPtGLsSdEafiN5UY1xWib6im1+0DRiCLsqmAaRUaRzTd5NwZfC4h0JtWkbwpsZP3YUuzkxQiwXGT4KOwXMhXwl4oNdUNp5EAyLbYooVsykCQKN1lcJeB1p3IPmWlLHZZRI.VsovWZkBkt8SCqfl2m755bm6bbgKbgzzU1rRbG6dMcX8FEd8iwCON287euXfZ826M38NNgAqgXcOG5980CezhCmEV1DHexVvnBd3KbNN+gGwS9oRyUuE9.y0.t7RvkyV17j34GUFkmzvawlXfbmrGaZyRpSbsiootswXq+2g1pY4ZqTwZwEKw1R81osSxZqVtxP7vpBMzXT2eO766IJA8o3g0os+K02btaa+Wl0Q9N6jBzZMuZ6LfUUU0mOwqe8q2qg7cdFD89TXIctaGKY6xKwVEODypdcBg2FjFrY4zzTgZa3FG+BLc6eBbxAsoyIkjcUIMPHjtAhfrVRzWO2CFV09Nq44Ecb2IIkLPDLfOFRU.V7Tq2har3E3VKdYbihT0TQzXI2MlEKT1N+Br83GGid.niAjjb2HQR0i0RTSLyuqfP9VkcsyC477b1d6sYx3IsFfWcrw6821wz6jGUqe7c3hemVnf86gVi.1C+72f26vcZWzMbUkghX+vvjROOETOBPtDZGvAPLqfhcygPDr4joQlXRj3y4xwW2fykkxYRrIcRsrJQgoF7L4ISTSgrDXE+uFJnGRrKoeq6oUmFya5mEbos4Uqv1wbeXUWsOD2ICUcO1o0Q.cXcCVc22vF6Ls0l3tRmGH1Vw9xUTRtyw1SmhHBW6ZWiYGcTJeLsWbpjBQVMIoYN5MHZI4rOSxdTFkeYNxecDSDiSHnMjUZ33pqxQUuJEit.YtcP8oVPIoJt11TUI8dZQ6QkgDK7jYgX.YGaSpsoceO.AMU9cAn1q3JrfcNGU+5b3xWff8lHtHwNwKMXHS2lcF83Ls3wn93BFyHftBbrJr+zwlUmmFZ8ntKrvs1Zqd5EDakBaQjay6p0O118y0ayk0+8Sy6q2ICRaLV89Ct02Iu9AwSaTrO3ORUXJB1VBllNcMYvoit93JvJsSXlFOtrrdcT2XZadVA5T7ggU7nmE6CXWRWIfAv1w.4dbJ0k3TLpzY7c32q0IN6oEx25mfdmlKhqa7uivsCMLFBsgiAsUsLRHF5Y6rqMQ+M9FN24NG6ryN7s+1eapqqIus5UKqqSDtU8XTAIli1DYb1CvVidXlczKfpKnwGok4eDMy3npWhcJeXxcSfPNJoQCuP6jLtMCrxILXcZnklC8d4NHTw9WS.jP6.CQPxhzn2jaL+kXo91XGEvGZHyU.XnYtvNEODaO5wIicXYkCobUk0P5plV2hXCz9+1iqwXj77bdfG3AnrrDEse1.Lbgn0O9NDmlgp2sP9dmBQbiwp2+31BI7zB6YHtsUQR0jmtwgUrIka.DAbcz0WQiIs6I.DHRDOV0spJBjLNM7xBsuxTzx18SFThbBJ1s5BqzIhqZpzz15ICAripAmlWTCyW26lGTq+6qiNu3VuiAFNcm68xqO70UWTBImVh9.k4E7HOzCya7FuQZ.r5rnhMsOTCo8QFK0UPQ9Arc9ivMyNGUxBBDR5XtXPr0Ly+Jbq5mmr7KfkBDWHMUchIlOmZjhPuWuCMCsZW9v+ZXtqZelc70xXRLQW0j9gKMLq403npWjExsvRfZejbSVxIJeISF+XjGOOZzQdggn1fzSJUnivmx.CPptZNOlmmyAGb.iGON44UHzu.vPEJo60cZgy8tcrs6wWOsI2om2F79GmHjP3z2geZOd2E8fBtLBXntolQssePLzlSz1Ra2UwzlXM1Vwsq6cUaqVtz8j5V0q6+5CEb3Z1o17T5Xh6Zaq2917IMLoZp2u5LZM70+NUYn02OrdkkVeanKD5gdtM78X3zAd8j42890UXfllFt3EuHPxHv7EUzzDZ+LLHFRLetBxM6vHtHiyuD0M2BqaFU0GSPbfz.xaxw0uHa69HTXFgcP6y2k6OHRmzzk1VL8Fv.s+3DPZbQMX95kpHaaXttLZhUoxhmEHZNl49Wi4wqfl0PPSpa.dCwFGak+.rU1CSld.Aux3hLpm2fyZAMQx3HIdTosgl5bt9bREiQJJJ3fCN3DGq5Pm2yCUejtm26TNrd2xs06kW2F7CGbqqEM2MqnLDpXa8ZBLY4oQSMoQG2.aMIM8FHyjVkqKrOk9t.nm2Yq5UszybEsjouL18ZIoz8Yr918vuWm12i6zq6cF2o8OuS66tSOV288tkX1t7yzk39KbgKPVVFW90tBgvRpq8jmYSspRnhLmgXikb2Arynmj49qygyeAbk4sDBL.li3vpKy11Wghw6PvOhB6XZpayQVrpMLNX0DwokJfRGurVkKog4UBLsR+q16cipVBhmfLm4UuJu87mif4lXxRo5LyZvRIg5L1duGgcKeDj5wjaxH1TmLVAjlVKoDuKH8U6qooIQ0FQHOOmKbgKjBEr0fg0tRpmuS62+gI2SuWudYCd+g6ThIdOAgUW1emiveU9MVudRqB7as9VSV618gX8U86xE1VasEOzC9fr0Va0SXxDwdqRhvXsfD1ho1GkRtDl3nTO4KB1bA05ohav73qQsdszPAQ6tvtgPbIVW2mscvOSUmKI9bcG4tcOD6Kpf5QEAEG9XMYkGw0O9Y4v4uJYihfMYvIF.ekgIYWh8G+DHgsvoiHFZSpuXWakmUIOuySo77jnQt+96yzoSYUeKtA2qf2+ykPhjFPPCMVoC9+D5DSVSedm5JSd7DOqaGqzWmTy01cuce92aiSKGIplDYw81aO7Ak25sfiNrhlPCnoltVhQjXIiKdX1x8XLq4kwGpPsKw3T7QvqK4vlWfowKvdtGDumTn5ZCh1pBmZJmVq1iOjGVIJEjZz+1ljenywPRYKH0yY1bkk5qxsV9r3kaQQFn9zmiCK95L1c6mfIYODrHO4McHILeIiUsKq0u5nY04CsgdOZzHN3fCnnnnkxC2qeFx8W38oGVsxPQWNh5ucRCI2NSc55UsSdxOLzHWRYGGtFtN3w+guajNahgg1rBQ1eucXmsGSdtiX.b4IIt1ZSLOWZlvNkOJ6T9vPcADRdooBH4JyatBGV+x3sGSTqSJQgH3b119jDRZdzI8dxPmZNjfrt2OFsWmmRCajZb4K3sO56Si8pTLApCKQIfFTbxTFYOG6N4wQWtURX3zDUJFjNr9NcnaaZHAP8dOO3C9fqTIg6RRbtAmcv6+PBUnsiHGXpJcK8ujXEmzEGWhbncut1y8ZEiEhsl05zPZNwsUuycLBR5Mk8Ci4qeXec+nGqSDwgdckkIr8Ni6KmuQbzDhXsBFrDqxXb14YmhGEodaLZYZh3HVHWowbSNbwqvB+UQsGip91PrxP6Ge4o8Upr19acP3ZsHMSKhsCVzjZcFwi3lQU304Fyedp0qiMSvGUjnAIjAMi4ba+DL0cIjvXbRdxPWKAQCDwOHo9VQ5U5BHYDtrrjyctychJ.tA2ag2eFr5lwdxPCNt0tkZgmSERZSvPmgHSKUEtyiO7zy8riwl2uXch8dRJW.ZrgQEIY40lkiO1oDBow0jFLTHawX6Eozddr5DDMGwZQk.Rlm40uIGM+kIHIBbFBxIlBzw9O6.ZWSGm1BX3oPmLz0AzJwDPM2fqe7yQPtIMgCoNTi0z1drZIzrE6u0iiQmfkhjwvX6PYsyPo3O4mkbxDtevAGbBoBdiAq68v6OCVBfwzRHvzIuAFDVmxIhiqkoVjZSiDucrDwgAqZ3DKfqqJV3I2HuS47Jt1s0w61i+2MPe2t0UpUoSxZUBZpwyAR6CcRREGvlzdKQRhAHQbFffiB6Ar2zODpeJnkobOo0IiI1ZNb4qPk+MRS6YxHFxnq+BWcfAfPxvkJnwLPSUDrex3LfVFgP.gLPBLq9xbqYuHXpvkmgOFPDKZzf0LlIEOHElCPC4ouGZmuzAPZPLMfI1azdHUQBg.iFMhc2c2UbyhSpaTav8F38cHgChr68.hm7mCSN0v2XVkKrt0xO4of+MRQNOSfNoF1HFbVWe9aDwgfkxxxDy4yVoXBpFR4ZJlQgb.6M4wIVOAiu.azlFLCwHYEQZ3ZLy+pzH2BxRR3arazVoo9yqa7mXTZCYeUBvG1tVogMQxfkZBTGuEGW+RrLdYp7GwnQE.fuQwFKnfc4foOIZytX0xzfYncN2op1Na+Za.n1PASFMCsTnwxNasEiKKaUvS5EdxM3dK799J9t0AGdSF9fqkA9tP9NwqXc5Kr1q6j+45eZ2oam1W06lm2OZw6zW8NJo0lon9eu6uSZskADGS2dKTBspLtEzXp4CDK9PFVNfB4A4h67TTnaCUFbgjL5DzJpzWm27nuMKkqRH6PB1ZhFOHgzj7VjV8KO48iRfnjzy+.0sFPCHlHwnOoxlVCZ9BVDtL2p56wB80vjGHnBXrDCNLMkrW4CwtkONlvAz3KwXKn16oIDHJFBAgXH8YiOIkydeRBdpqqI243f81OMiJ0VkAUL86mFdaStsNai+FkGV28zk5TLXbGLVsA2YHhjnKhX6mDKcL3GjUUnSDpWZwJ6v9a83n0SQZrsCWzj5c5YFA4FrveYpBuI3pIoXCIYV1JFLcx5rjFdrzNDPSUrqSkGRc8oJVDWfkgqx73kYl+pjO1iXiLe4Bb1BLZNEbNll+vH9cQCiwH4s48R6kHnTO.dxNCHOO87h9.SFMlhhhaaeyFbuG96dWL1f6Z7NwV9xxxdRTlZEJaqwiZPRptoDFwjrGhsJdDhMIiLVaFfEWdAdlysV7xrTuBprDiwgFxAsXfHIFGPZTPUKhjApCKYPHwcKQDT6RlGdANr54nIt.wlkLrooYTWlNgw4OJSy+PXzIPzjx4FdLlzmgAOVIfX7nj7nSIofnoVqRX2c2sWmvFteYCsFt2CaLX8Ab7t0tH8hqSqJjRqpD.lV0J0ig.VCDCV7US4AN3iRlYKPyvHEIFtmawyBt07WlpvqQc3PDqljB5XmmSqzn6dNYQx.jQoOY4olctAOGxrlWgCW9xHEApZRZ40nxoDWZnvrG6L9wwEuHhNt80G58rpKCoIO8598USnbUUJKKY6s29DB326jBLrAmswFCVmAwInO.ZKitssgE0MnERCIBmMMjCbtjGPRXa1t7gY2wOJzLBeCsUZyiZpXY7Jb3hWl53MwyRTS.saHc1yKqAM76fliVfVCVPjYLu9M3H+qPs7VXbwdof1RFZyH1o7wXuxmjX0TrZNNiIMnYkXZfbD611BmngkcNGUKaPvxN6ryFhhdeD1Xv5L.tSxWR2EyPROslLYRJY3s7zxZxPHKMDW0.VwQlYB9kEr+VOIRyVTWo3xyn12f0BFaEGs7Mnl2hfdKrYdvnqFEgo4y9.cqOhHgdtwoZZTPUyawgKeUlW8VH4AZviMOkv7kyhLw8.r2nODE1ySzWztMdRw46NUXDscHdjkkwt6t66nX7sA2agMFrNif2IMWpStbRZ+T6TeSrHlb.aK6yaCOTA0WvT2CyD2CiEGc7mRMBRFDji3vEuDMxUwjUChuOA7IVsmHDbRLMZm72REHMIkfvVSs4JbXyKRkt.bN7wUCFB7Yr+nmhQ1GFIjmzY8XCh5wYDjnl5LBMcyH4ovRiogGh26w4br01SXxjI86C1j2p68wFCVmwQWdrhQ81FIUplpBnFaaaGhDZpYT1Tx3Br8nGCqYLMUoQBercBEYx7bi4+.7lqh5VR.OwVBihZHhquW95zZrjWXdBTSzdDMxUoJdEhVeZNGBD7JAugR29rU4ih0uG9JnHy12GiFSxvjzNjnVkWpDIErlLBAkhxLlLYRuVg0ggCRhMFut2CaLX8Ab7N4YkpJNS6LJzJLd7Xv3fAZueHjFK8AehlBFK3afB47r63GmsxuHDxIzXvYySSxWSEMxU3sm+8IvwDnFqizDSVEB9X6LKbU9qBH3UO1hFNd4U30e6uNMxUw5ThgzP5E0h1LlwYOH6V9nXi6zFd2xTuOZLD7wzmQX020UgeZHFSjBc73wr81SOwTcBNoFW8AgjtOTHF+Q4m2Op+b+QE1Xv5dFjBqaznIDiq7LIIGvR+TGNMrJhDpxovbdlV7HH0SvptUFFLQZLGxr5qvQKuLAyLDWZjpEiQxrqFxCIiHoQFePiDyNhar74YY7pDLGgRMFKD8JgZGScOBmaxGAIrCVJvbhAMahhDc5uUZDczjB4r86XL5w4LLZTA44ovYOKi2MCKqa.5c6185XiAq6APhF.ICVSmtMwfRSHllnNRJo4PJY0FiCMZI3sX0sYm7mjoYOFgFvJol3LJfXibb8awMV9bntqSDEM1ZfP7oJQpJ1VxmBkH4NVxU3lUOG0bSLYdhZEh5SEVrtf8J+HrcwSA9rVipIJXnQKZzhPpmHW0rydLVEwjRpeT8TTlwVSGmX19YD7tYL49UCPuWwFCV2CfNtXIhv3QojPG0.w1PECgPRi8a0T9rVdZgufwxCx415oIT4vYbHhIow5E4zny4vkuLQ60nIViOlZz5XrFqqsWA0DuuhhhIqgaN+4XIuFpKjFPthhDh3zblXNG6L5owzrOZzQL1MW.6DIvABHTaCW2o4VqTdUkoSGmB+cCtuCaLXcFGo9IrSKx.WlEiy.l.XCf0PSraZ435uv2XffGbw8Y67GiQ1Cv2jgQJSxRrjgKWXY703n5WBLyRLMWBfnnZRysRDJsBwtj49qxaM6YoJdMr4YDC1jwwnfoZLma5SvT2ChMrCVbIUOyXZ8npKWXw9YsXTRi1sfpnsbxx4bryNaQQ9H9fR+fd2hMdP89GmcNZuAmJ5RFcmv8TUMCiMQ0fUIjNcgd2.FsSJXLXwpkjE2lys8SQb4XPy.iPSvijo34Ht9guJA4PvsjJepRdMMMjmm0RihZBl2hqe72mp3aRzLGqKifOI8LFeNF+tr+jGGWXJNSAVtcULcHy1ocBUBsM3cq9p4bN1d6saKpve2mT82M721I9+9MieaLXcFGRm7ESJzuac3aSjpVug.MZwZJRp1YHMPSQBDUOFS506jorc4GhB6CguN0hOQcIAp.KLq5VbiidQrYyHpdPSMiLsgzEjYLO7BIsZ2bLlBapJeRFQOXXB6M5oHmGnsOBaRa7cIbW7DEOpIzxqqAIgmBPywHEIQEDgQEiALefnJfePB2OXzZiAqy3n6ZVAfXjYyNNkypXjXL48UGED7siw8NJOXwhDEFmsGV8Rr83mjfOMQoUC3i0XyfnaNW8vuCL5sASflfPlKm4UKolkDLGwgKeQVFecDZnvURUUENSFnEjI6w424ifwuKFIqsGGSMecWkI6TmgtpClRDea9szgypwURhbRq2u28hzMUE71w66olyF729X8F5sSljSZYURCr.nttlEGuDwkQlIGM.zpNnIwvSv2kKHwf2GH2TPrNib6ixVSpI+3+ZBMWGoaZ237TWccpkWjqs7YYpb.EXo1GSCxhxFVFtAGV+p34VTjYodwBJxEzlFjlsY2sdLl5dHz58wGrHFGMwz3JKUrQg3vNxoK5PzDC8EHD7mvnkwjdR2IEr3CRM.8chA92oswt+9tYaecIzd866dMrwCqy3ne9+EirX1bLFGNwkF0WzMbHh8xNiFk96WDAULIJN3mRI6wt4Wj7lIPHqedGZb0nt2haN+4vUbLdYFFm.1DuqNzeYlEuFZVEABzzzjBWTcjKmmo4ONpeGDcLVSR2p5TrzUy7vA2X3PjnSO2aucFE2ICq2qZX4usvFCVmwwP8S+niNpOju0WkdEQOoW0CTQvah3iMjEircbBWJ+wYTyAH0FrhEWvQtXIyVwgG8x3iuJ4YWGUVhj2vMW9R7VG+rbb753s03sATqAmIiB6Vrc1Sv1EOIZXDQRR6Lljjzj3u06suqat.+cG2KuOZiAq6QPLFY1rY2V3AC+6NCY8FyZIbpwFwDTJzR1I+QXa2ihMNkPsAGYHQArJd4V7FG9rDJtNMbDpLmiW9JL2eUxJBDMo4cnykQcsAitG6O8CSV7bPHCmIwc8Nw+ynlURVyFrA2EXyYK2ifllFpqq68d5toIfMJXjHYVa63zpvL+UsA..f.PRDEDUDm4AX53mFm8BrbokH4DPRscSgxUW9R71MuB1hYTWcMVN+0H5uN4VvDDbwHNxowOhQkOLaM4IHVMFWzhQBznUn1.hFvHJFQu8PBuM5NbugWC2ouaq+XuWwc5368B6yVGaLXcFGcUKZwhE8Ub6zpfTWniC+Y2qGR43NDMDhaynhGloYOHR8HhnPVDuDvlGow9V7Vy9dvnqwQMu.UgqPLdSBwkjlvNfI3nzbA1e5SQtYOBMYr5SAPMsCUi6tbRcmRJ88BXSXtu2vlpDdFGcdTc7wG2xootDWmvPUL31qhjhpf2GPrNBJD0bLrM6U7HLu50XAuLR1RPin5BxsMrr4Y4saJ35g2.s3Fjk4IZEDIRrQQZrbP9Sxnvkv6EvAQiRTUrlQfWvJJRTQs+vUZ90M3tA2efMdXcFGcFrVtbY+8sdtp5tugdV08SmjX+ty4Rh9GEXzwrc1CyV4WhPzQiFIhPsugPbNAyM40tw2hiBuJ0gCwZMng.FrIA4i83bS9HTDe.ZVDv4.0DHhRtXwDAwZRsfy837L5dguCePBa7v5LDV2aoNYBdwhELa1rjgmVE4z3bmXXhNz6pAuiDCQJbYzzjzH8rnCmLFqbQll+3jU8BT6qQDKp.1wVVVWygG8Fj6rrUQNnAj5FznE76vjxODaO9oQp1EjFPqR5zNBw5EXDK9nmfIll0fp41litCQmwUu2ynhxa66wo4s0GTTez+1Nbu0yC185XiAqyHXEoIOoWRpprb4xSjj86FhSlFRqql5NJfXDDUffCqtCScWhhEGPn9XDSME4FhKCrW9VTaVPz6oxWSVoEiMi5lLbwC37a+QP7aCMEXLwjVsiEz94EMACDECRTvn24gJ+JUZ31y0yGTLJsA+nCaLXcFDqy58Yyl0SLzt6O9d7B4.ciXZkPCHTvVkWfKM4I4x27sY7z4vxiIutjvaNmcUC4aMkCya3XpYoMfYzT1K9XrS1CiYYFhJDMknZHEFnBpQHHj3jEBn28iT9gpK58CdSrA2N1Xv5LDV2KqtPCWrXwsSAfVdW8Nplkc8eCJpDIRffwBhESvgS2kcxdLNlKi+ZeeJpUlrHmEWSodwRLSEltqv9Ox44Eh2fZojyegmFSbOnALh.hKoHoAsUYGVUuvzVqg6VUCcXneC2WL7w1f6swljteFGwXLk+o6P4we233TvjFVyIiaABlHhyhKjiqpjL8Brq7g3hGe.m+xS469u36vG5leT9G9Q+Oi8eqGia8+0Kx4+yi7jMOIWPdB1N+wodQIFDP8oPLUAaTHWErnXUOVMoZoxcIOrFlCtgZIeG1DZ38GXiGVmwv5Fkpqq6UgggWHe25wQZZKGwZUBwTe6YLVDLn9LxKNfGdumhE+fuO+q+M+S3+t+4+uAehOOjE3A+b+Sge2eK9e7+k+G3IO2+H9v+zeb72JiQ4aA9.VKTqoPUEahk6IXZUWh.uaqYttWUwXbUUM2f66vli5mAvvDO282cnivnmlAp6FCWNMCenIEtlnDCMjlNXYnFGXJnPmx72D90+k+GC+892GZJgBCH6.+G7eBOw23qA2ZGtndIVlcNlGEzRK2Z4QjY1BmwQPzjRkF6ZrYepcgdOteHDB38dJJJ1jz86CwlPBOifSqL9PxCqSieUCywy6zMAPiwt7sCg.gPCAih5xnJZXdkgY2P3IdheFvC5t6fOOm3rkfGN2C8jDYKZpxgfhSVQAASHMUnUWLkr81MciZRC006lswAFqCgPOcM1j2p6+vFCVmAv5dJEBg9vilubA9X.LBpPeHSxo38xPi.gteFpHKyRL.95FFU5nnzQThTIQrilvqd0i3Eeyk7ce9q.NEQOjF+wX1dDHBW9Y+A78t5U30plyBeElPfITfYAjghI1PkuglXqmbpRnFD0sxnT6sSyXk266yckJvQyNt2.9vvfWuki1XP6dOrIjvy.3NcgWLFoppp+4LjXo2sstRDkXLMrJxcivWUgpA7MJjmwUO7F769U+RL+xuDO6acU1+O52lO9+feUFkU.25X9A++7axe0K8b781qjpW3Y423m+IgZvW4wJVLB3IMNvhBnD.5TRTChvIz4p0+ldZgCWUUsgSV2mhMFr9.NFdg45W71zzvxkK6+6XLh0ZOwqY3jP9zf0XIfRMdHnj4yfPjsJMrL2yqb8Wk+cu92jK9X4bvV6v+S+2+eM+S9B+gr21miW7ZuI+kuxyysdjyyKN+575+UeE9ne3OAO8AOFZPY4hJlNcJRrAiQRiJiXpeG0LkfFaGcFuynaHv16U474aLNceJ1Xv5LH5LH0UgPQj9YD3PiWhHuis7Bjx0TT.WoiPPY7zso53CQbJWe9M4e0W9OfqOMxw0d7ytN+hermf+xq7BL5MtBGZfuedCug+HdcogI9Z9pe+uEW7m6RLsXLlPLM.VUAS+rFTQMJhQPiJw36ddIDQR4Yq0KppppdIhdSXe2egMFr9.NFRRxNzcQ5vFdtKuVcdgzIXeqy38guOFf7LG0MAhdCNqkCO7PxKrbT8M3695+.9S+9OCid3C3nqufmspgKqynzoT3WPYwXt4tNtV8wju+9bikM7G+M+Z7o9D+77niJAqIYPLRRTlMBdTPAilBE0JtSDF3oER356KBg.000TVVdWsuaCt2AaR59YTzEZzPOpF15J2sh51hEKHuvgDUDejISFwgKtEG6Z3e4ezuK1sGyQKlSk0x7wS3pSmxUu344E2YLeKwykKbTevNTWjyRB7pG+17m9c+q3nvRbixnQSruJQn9zPS0HBJADidWER3o8cY9742wuSav8tXiAqOfi6zzVIDB8M87vjs2gg529525z8cLFxJb38drJf2yg23MYuGXa989ZeQ9A250vGVBM0oIaePgfik2XARLGisfXdApKm4KW.YBGZp4O6670YgeNM9kDLQh4VTSxKwLUvEAh2cd+z4cYWaF086CMVuA2+fMFrNihXLRcc8I3jzPMuZcusVOjRQj14.nRnoFiDPLAlr+DtxMuJekuyeEU4BVmCDCpDIOyxX0vEGuC+h+D+LXZBXaGSWsuwnEv29k+d7M9deS7FOpU6Y4dLFwDULgj38I2E7vpCq23y000+HZO8F7AIrwf0GvwooPAhHbzQG0yMIiwfqU+q5LfMjWRcdj0cecB9m5CXQvHQ7gknt.0kvuyexeLuva7ZHY4nhASVFTUiM3wM6P97+z+D7e7m8ywkbEjuL.003LljFWYUbSK3O3K+GwsZNFuj5YvlXZZOasVjnRrMmacaqcnmuUC1165WxtWe21e2j.Zc0qn6223A18dXiAqyHXXtpfDkFF1RNqqZAqSrxgpPp0ZIKKirrLvHod7y.Kngeva8J7u4q+mgOOiY0dZpUh0P1nQXU374S3S+jeL9odnmfe4epeNxWFnH1ZnvpHVAaokm6ZWl+hm8YHabNU0yw4LXxLb77YXyKHOqjllPu2YmVd2VmWYCKpPcccuQrM39Grwf0Gvw5WH2Y.ZXo8e2jYk9bVwI8lIHFVnJKDAynRh4V9s+J+w7FxBV3L3JmPd1VPzQvCyObA+F+h+Z7Q2+on90Vxu1m9yyNlRrAs0nmfVuj5fm39i426O+KxgUGgHJQ0iJvnslxhlZp8AJyJui4Xackzb3MUSpsZZj2uA2OgMFrNif0MDstAqNCY2IIlAt87EEiQ79HVaFADd9qdY9Je2uNyxZHjYnppllP.SPfE07TW7g3W7i+ywDFgs1x4lb.epereJx7JZH.w.4EiY4rYT6DdwadU9JOyWiJSfrhL79ZpqWhMygy4vuVSaeZxJS28OLTwgeWNMrgTo26hMFr9.NNMgpSUsOoym1E2C+82IMxxpvDxY6hw71GeHe0uy2jqWcDE6LBebI1QNzXCSKyXpG9O5W5WkKsy9TOulxoSnowyu1m8WlcrinvU.YkTOqhrhwrHzvBSje6u7eL0kBGt7XrFkLmCecCpHDQvu17SbnAog2+vGeHwYuSXiQq6MwFCVmAv5FgNs72bmZ52SS0F5FzpppngJV1Liu+UdQ98+JeAriJXYSMD6Fzo.KC7QN3Q3S+DebFYbnwHKWVSlX3hS2me8O6mmp29HrQgI4iHDhXbV7YFdik2h+fu5+Nlr6TrNg55kjW3npwepa+m1eud3tc4w53iO9cb+1FiV26gMFr9.NV+hNQDVtbYeK4zceuSWvu98sJzpHRtvbyb98+5+gbnaNQqEpELYE3WVQdiv3ZG+pehOO6nSYwsNhIixYKWA1kQ1uXK9HW5CwSe9GiIUNDugrrBBKWha5XNhF9qetuCu0sdaVVu.WtCEH2kQzmTUhSKLvgaucbup6uGJMzav8WXiAqy.X8KlqZp6kZEUUz9GKhpA5zH8HqBixPa01roaNC3JbDKgu1O3Y3u7k9NTOV.qAhQrHjEEJCV9XO5SxuvG6SvXoDMJD7s7opAxpgerG4o4S9j+XDObYhxBpBFCQTZbJu3adY9Kdl+JFsyVDrBGWsf77bbtbznjHQZqcYYPtp5LTcBDUrR56PSXSR2ueCaLX82wnusUtCnW35ZawkfF4lGdXaU4LDHPj.QI1NXRCDid7pGeLw8JKVHJng.hyhW8TVjQcXI2zOmem+ruH0kNBE4zPCHQjnhKZXhlwuwm6WgQhkXiGUbXKJYQUEk44XaDbyg+d+j+7rqojrrLZB0Xxr3WNmrQ4bsiuA+IOyeIuY0gTYTTqAeLwgJCV70AvGPaBnZpkcBwlzOa4UVLFwfjT6gnRDXQUE09laqguWWLC2f6cvFCVe.G8dZHcSzuTEB0AM4r.nRxiqnnnlV5AHIiUwP.q01RGfZPhLudI01H+A+4eI9qekmkXVhPlQAxxxPq8Xp77S+zeT9nOxiie9RxDCFiCwkwhpkTTTP07JbdgG6bOH+RexeAlcyCgX.qwf1lP8PlgevUuLe4u0eEZlEali55Zjnh0ZorrrWm16xOUGAQ6MF0t+vXRd.JRh+XCUb06VM.6r.tSL9+9crwf0YHnj3eTmJMDiQrQCVZITo.Ai.FAKBNM8S.BwH1rLhMsCrhbKuxsdK9C9q+pv9SSe.9ArOuwyd4S4y+I+EYO6XF4JPCQbpPrpg77bZBADqkhhBxCvm4m4SwCt6ArU1HH.zpTnYiJYt0yeve5+VtY0w3xsHAO0UKv3DTi.s4kxZs.fSRRnrgHhokDrsdU1DB3LFzPKi8Okdo7rDdmZIo2KOm6GvYyiv2GgSTwOjSnAVRexnsooeCqBuznIwxS0j2UVqk55ZJxcXyrbTbI+Ie6uFO+MuBMiLT0TQt0gtrBqZX2ho7y9i+yvO9i8zr7sOhIEIufR7sJRVQde3XFEL9HOwEeH9re7OExwM3BPV4DplMinUPmTvy9FWlm4E9dDsPQQF4NKABLuoBWYNMAOpIwDeMDwYrHJXoU9mgDy76B8SUpWVcl9h22Oa6mk+d+CK1Xv5L.DQHDS4xoSVUNcNVkLdgZ59qVZMDntYIiJRpI5gGcDKxf+Ueou.rSIKnghQkngHEYkXphLUK4W4S+YXTzQNVZpCoAuJfy4ntdYeB7mOeIk1bJCV9b+jeJ1UJwEExrVPinYVtkeAxti3K8M9p7523pXrJYVklfm.A7wDUHhgtQO15CViXaXuoahlt0Qui3.9bsI2U26hMFrNiftUSWrXwsE5SGupZmjVPGukZStsXghLG0UK.QoXmw7a+E+C45wEzXBfFoZwbJyKIWcDt4B9O7u+uFO5AOD5x.E4iHn.sRRSn2yNEQrj6xHz3g5HO99WhOyO9mDl0P87Jx2YGZpVfY6QrzF3q+7eWdt23U3FyOjnnDBovKqqqIOOmfFInwS3IUmwqnrR2u5drNCVqGpzYEiVue1NOq7c7uIwFCVmAPuxEfdBUFUkUSJGM.N0RtZQhBQUHZrDssdp3avYLDLQ9duzOfu7y70gwEXaOo2NcBGM6XBGtje5m3ixG4BOJi7V.gZMfj458nxGCjmmiFhDZ7sJ+oAmwQ1RkO2O0mlKM8.xCFZZ7v3RhKWPCQVlE426q7EotHREMXrfUi3XkAp.JpXIxIShtEAutJg7lV0Gc89Lb3q4r.Ns9o7Glmy8CXiAqy.nWtiiw9QdUOLIM6z.Xa8vRCIuT7nXcNZhMD0.9XCLxweze9WhW+VWiJiOQ0gXh9.k4ET3M7Y9w+D7DG7vLBGZHIbecFRhwXaHg0HhfK2xrEyAwhFErdgm5ROFehm9iSdiPlJPsO4clDoIG9Fuv2kuyq+hzjCVqgvxZJKxnZwxTR2aUPhN9kI5JoSV0TSV24E45TYX88amUwFiSmN1Xv5C.PWiIVCax29gs.RO6tGpCVci+8PK0ED0fykij4vKICQwXDStkXogu8ked9VuxygLNmhwEnZ.iHPPIVE3m3w+v7IdpOFmaz1HUQrlr92emXvHJM0KSDLcPXawVRr58AJvwuxm9yxA1IvbOYYEcrXExMzTH768U9Bbi3b7pGqA7KpXbdQZ6M.QiMEdXqGTgPCnIiqIZd3PiohPzM1uFFtHb+YHS2qiMFr9.FtiJPPKkFVWf5rR5BzrrrdA7qqeCEQwXAiyfYjiCiK429K8GwUleChNv3Dv3fPDiOxtlQ7Y9I+jb9w6B0dTuhijQPaaUGMAsehMGPWQf0PfPPYxjsX9gK3ouziwm7o+XTFrvBO3CXJxnVCTt2T95O+2iuwK9cgRKtbGk4NppVzKEN000sFESzbnidFhHXHQcCf9QW+PrwP08tXiAqyHnSgFVWQC7gZJGkmtn0j3zzxppDILiJDiDHvMpOlu6UdI9ye9uE9oNhVk427lDLPHnTrP4Ce9GgO0G8mjIYinZQMZHwtbqBRPwEIoI6RxnRzHsirKkbqCq0xxpFN2AWfkW+X9U9Y+bjWCEAXR4XhKVBwHK70TOxw+lu9Wka4mSvoLuZAEY4D8Absb6JLPUR6oOACxSkX5mfNqKAzav8lXiAqOff2IscpKo6cg9L7BRKBpOfoUeohBXyyvW2fs0SkrQYb4a8V76+U+hTUJLqYFEixg12WqZ37to72+m7Syd4SQqCnQAWdV5yVioSThIuqrwAMRcKYOssD8LKKiPc.iW4wuvCy+ve1OGkMF7yVhykgwXnpYIgRGeim+6we9y9LbipiIaxndMeO1j3YVVVV+2yaW8FZY9e6zu9rb9p1f6drwf0GPwocAXWhtg67nYuSwNsh7+O68lDikklcee+Nmuu689FhgLxrF5gpmk5lMkDooHUqAN.IQZYJKQP5AXuxKDDfMzJuwvK7JCu0.FBRKrg.jgVYuwZvlVBTBjp4jHgs3.XSxVra2rY2MK1rFxrxgHdS262243Ee26MduHirprptpLiLx2+BuJh3EQ9d22v87NC+O++CYiPsx8VcJey68Z7K867qgb7DXZEms3TZlMiJClmi788I+t3u72yW.eYGdFpmzfV2LtxOY2wXKcgOeN2mZaaQbmJQAJ7x5FyOlXR3G6uvOBMafPtXlpJP8rYEUIcZfe1e8+Mrrw4r7ZboPVzfQY2BS4GV5mkx9TNbcOJpMrO.10SrOf0UXrCuhnjgErU1FhQFGsRwRodq6RHkREE8L0hFibV2Z9W8K+KfMMvFOAUJwlHdpiFKP99K3+r+8+aPXQKS0ZBHrpKQm26byB3AuuDPoWsGThhRHJXVpnRDlvlyVyAyly50sDj.e3abK9K+E9KRHYiky0d1BB0UrJ2wW80eU9xe6+.jo0kaa2IjcpPI20q5DaodCk.06Z1DaK0N6w0arOf0y.vcGmyUYzsYAtFBrYyFZZZJ8qpKQSSCVpL0v0oV929a8avW4U+5zb7gr9AuEnNtXLopF+dK3+ne3+ZbypYbfNAeSWQBWphrJ0RmBofPNpXQkjBlzmcCfkxkambg04Sqav1jIFJ8UaBA9d+be2biCNBOkImMleqaR2hkLY9L1T47O6K9yfNMRapkfU1iQwDlOYJhW1gvLNI2vUoLvQJ6GIvXS22qRCW+w9.VOkwEozvEw1JPvE4fkCjHUVoktVhnDjhhLLsYBlF3MN697O+W9KRWsxFRHGb.3JdFZOcMGka3G66+GhaL8H51jF26vfPwoaTsPWhfVVtZ2nMmnqqqTJVtP8.WzhJOHF3YlzzfuIScV468S+Y4O6m76BcYhIwZVd1BpqiTkaYNIdyW8qyuxu5OGgoNRSIiwJMfmJhLn6NYCLur1QaSihA+N7hbVZePqqmXe.qmxP3hMS97dyrsroz11tiJML7268MDOJJV6FlNIxpE2m.AjpI7y9a9uk+fk2kzz.cRF2.wiDHfuLwO4O3+A7oN4iQ6Zi0ccHwJ5xIZWurTFWWFuMg2ZHlfDpvCQ7fRU8DhMSPqpoK6rXyRRxFHzQ9rUby3b7yVywdM+U+S8E3S17BLwi3aVQn8Ltougad26vGo8T9U+4+mxcW9sXSXIcZWY.CliDTnRnd5ADplhHgQtVYRQgFV2toHlehPtuLVD4c3iB1imEQ7o8Avd71igLEtHGr1922l5vRJylLg1ThIGNmzr.+1+9+t7K7k9kQOPnU1PyjZVuNgmRDbgW4VuL+Pee+4g0IpppHdiFx4RVMSmNEKUV3ZkRlfdNQ1kRAZRQoETxTUUyjI0XDHosrpqiJApBUPUjSWujO6m7SwOv28eJ9o+R+h7JymxGYiwMWj3icqOBG3B4Ni725OjIehSPquIqcn0xjztxtK1ZkFwiCxPQgfYx3tTR3BSSDemOPXOd1G6CXcEGCL3dvVu3Bk8HZ.KJjQYgCYuhMwDe423qw+x+ceQZCuEUgEb5xL0giPUAoKQSqwO4eyeJ9Pu7svdfgYYV2sAQJK0bJUjgYFVzYDTUH3BHJlCIKQn1XS9LHEwiJsZGoINwINRkwcWtjU4E7f6dOtwKLmacfh9seC9g4CyKsthO1q7Y4EO4lb6uzuOK9W7qQyO5gb7m+.9iz.sgpRi3MnxLzTFOBNFh1GbxXbkkpqpGCP8NUp8d7rI1Gv5JNFxpZaa8ZbhYnzKiBDpaJDEscC9hGvW9m+miEesea9zRho27X95+wuNqXIuYcCZ8T9ju3Kwm9OweRVZqoYdEYui04Ry6Cg.Ka2LpRohk6mTmfFJ8zpz76LOXy84tO3Tt+8VxoKWvat3s30u6axct6C3rUq41KtGY5XyY2iJskfshuvG9iwG6Ny3+5+K9aC+X+HvYKg1J9p+i9GwW4m+WhuqpZzO4mmNblFCntSzcDbxBj7LZnrX1CJWwCw188YVcsD6CX8LBF3fUQ8XFJMLfjDBpTzxpfgu5tb2eqeKd4+e9c4j2597Ruxs3O32+qwekO9KyW5zE7KOS4aspiSmp7S+y+KSncIROQMqqanqqqThUOgPMyJpzfH.5Xy+Oa4RVtdE2c48YwlV1zpkfXdGYoCOTjR4TPHYcbiW4Dj6dG9HmpbXqw2y+g+XvO5OLDmAmbCHa7Y+67eI+L+T+03uvO3eITUYknzj79k5tqWy56o5gKPe.zws.nuDvgrq1Gz55G1Gv5JNtXFVae8A.UBHHzIYRmced47R9M+0+U4u52y2G+.+D+jvG+CA29U4e6+a+Cn8a8U32OarnNvq+5uN26A2GoaEVtkbNyzoSYcaIfknkoBNbeMPVyPHddVMlQNHjqTjIkLyTWoybR3HgDloHM07VKtOmfQMJyjZ9De5OELYB3MPLBZKLulO2m4SP68tCmd66PyG8iCaVgnNIoHMNhpXlRj.Y5kilbltttxyUxC6ig6w0GreJgWwwPIfsss6nplCv65ntJxltkLIjI8M+8Xtuhef+69uA926OC7huD7o+b7m6+1+GHuohO2zo7gSKInq4ArhSUmtISYUSC2NkXQUf0SpYQcMqppocxTZmLEqYFVyLZCUrFk0njBUXwHVHRWZCq2rrOCsLtsFK2hlZgkq.WYSWlyL39msf7270f6srTBa6ZfVPVwq9leKjIJGcqSnKmoSbZUHoFVTvBQbJDj08yo7wf65HrWNVtNi8ArthigS9FyffszJI0ITKrb8ozzzfZY9i+peE9repOATUwlYS3rI0vgG.cvOwO9eSNpRHztfoyTxwDVCrT5fIAR0PtVnsxIWA4JXCczJIZiFcUN4nSWvHGbjZkN5k+lp.R.z5AUf.BAmllHU0AlTMgfNktoSY9MuA+L+i+eG9U9WC4EHquKr9d7k9e9uKZ2BdwO5KSmkoKajPH2KMy6DHxbnW1nGjamwgQruTvqsXeIgWgvEsopsytpqqabhgCeMqNVDL0vxJUdCXMrYsARMKWtFlGAIAMJ2909FzRlUZhUcmhWWSmCkQtUAZBSMvL7d6zhf.h.duNS4VQM8z.t5TqJlsA0frkHqM33DCJ4bhUICnhJhLoYJmd1o7a8G76wmYxw7+8+q+Oxm9m4eLelOzGku1u1uJ+de0eG9bee+oQh8YR5EKASjLAKimRH0MDUEwSDk7XlUUUUEWDpWNZTQu1PqguS1KxqaYatOf0ULbw2bNTtyXFDW3Mf4bgc5jEVSji+7+Y4K9u5eA+Y9c+Rbxm8yVJGKBb62f+4ew+0r365CSVmPk0vrjLR.SwRkIw4PlxWKDWU6OlJFeZU0D.ibmQpskHBw9L9xInxyHIHh.DwBArbfJp3kO7H9Du7mjuunwG8O7+Ot4seSd8e8uH2e0Jt4DgerumOEuwwSHYFcsIBGTQ1yHdgZCQTrbwQfFTZhhSW+rmEecwWmeTAV9NcItut0Ou8ArdJiwIZ8Pxmx4bvJmyixjLxtK9akWZzc1MVVOgealxqdvKw+h+g+C3m3K78xrW4iwc9leC9G+y8yxAelua9Mdq2fMb.UVfpp.4tMi2mZLVTkAQwMGIDvrsKCEDwfdQYV7HMg.Salv74y4nlY7gm8B7hGbBu3wGyQGb.glIb3MtEGeiWjYSlRbyB93KecZ++5eHGt91T8m7kX4ouEuvIS3LcE2d084ESanpoFnewmC8Auv2Oil...H.jDQAQEIfjLznRdqmyDQFMg0sed8pR1UONAcdTJuwGjGCOKFDae.qqXXaUIX.CL4NDB6RqASPHVrPdy3rXMe43Q761bSNV53u+O8u.Kt2CvmOC+U93b+o07W76+uDe+SBLqolMsqnoIhSlbxI1TVXYW5kb4XbKEi3b6fGJkfMooliNXNGe3bN3fCXtNii7FhsJgdcfWBJIf1t.R1w6BbTXNmlSjVcJyN3XlJ0jaxb26+.5zZrMcHIiPcYWIEoLwxfHjyBpqjPJtKctb8aGv5pDoQ+f12Aem9ad6BJcw2m8r.1Gv5JFtnNWIWHiJ19MndoDoPnlrth6Gh7k8Z95e5uedyGrBcxeRBSlfYsLMB+M9Q9B74OogaHcDCIRoMH0krpx4LUUUjRo9.C8ZDO5NLdOvV63XTosaIUUUDLP6J7By8ROuDMfmLDxznAzPf0cNq6fpYGRaHvh1DdmibVhW5vWlzlYzz4naVi1zgpoxtKZBFEdgYZfDEdeo8kJGi6eq7yCX+qxWAwNxBrp6nBAWrg70U0z1tFKBgCOju5cWv2TNfCt0Ght4I1jaoVx7xRG2u9XpqBLKcJrokJTrVszyJqn7n3U8YUoDMkx1.EJSkihIpNPnz1yVSUngfGvSYfh8hoZjDk87SoOaMKipUDBA51.MSlxx1NBMQlVWSnKSdYKzA40mQUU.MJHXHdlARqRPIKYTbD6byh8xBXcUnrvGkPK990+1m270v8ArdJiAlYusxLryu+BxlxN+ctQWdMgJHYNlGXQm.USXSNQHVH5YUNScdCyiFozR5ryPLil5ZR4LHfnBtk1MCJL7rQHFI2yx75IS43iOl0qWyctyZHq3nz5NZLf6YBACyDDwPwnJ.BIL2v8HYDpZlSrtgZMyj.nREKayLoQYSZAKjUrIzUj+4LndjrARvI3YZLnDRRGCrewmSupfGGKH68Rvi2Mkz8rXvoKCOaMZkmSvECbscvpc4hkizakW0MSYylVjXEDqoqKWLZU2oJHHoMbPSfIQALi55Z1z1BTzh8.AH26vgti3J4z4AGGZ5+w27D9PezOBGeySJWGBRuoml5skqrjwHOtD0klzaXVZTesRT76PUbrTK41MDqTVuYAUUBlzqwU8Z2kCXVBQK61n5FA2Pjcy37YE79kuCdwamG0kqKXe.qm1v6KuQbbOuyIcEkFEPEBgh27EDGEif3fUrgKOWVWkrKz0tDrNDMP1DDsh11VhXbbcEz4TGZXcWBIVggBgHcYmPcCcYuXJpRwhsBU0zlxEJYEp3jiNgJoh4SJMZO6Ij.fqPFpB0PmWTNzTlnDIm.KGQkFbKPaWhoyN.SCEVqyfAo5HAX4pyXpTSLInoHpVUVKmZEu0HpUjUnSJAvappKt6in3VwunkdSk85.tXF1W1fYddA6CX8L.1tWVvP4DkLPRcFUUMz4BKVuouWS13ansdqruInHYiZMfkbBZ04AK5WZP254Sku6DJCghn4Mc5TpqKzMHFibxImTLSUwHnJJghCTiz+8Afx06HE5R3domXZ.isxfS259LULLUIK8+a0dskeqrt.xCRa+kjM5E+9qa357is2NrOf0Ub33OTi2gy6AhYFZUEcN7fkqF2utgoI5lg3vjPEAc29fMzv5gx8N2jGN+Su2V9gO3fCntpDvRUkSN4jsFPfOVdV4me3dwsS4rg.tO7X5bm4QwwRcnCNiiVB.iqEoctHRC6b6FBgK8965BtXq.ddF6CX8L.1tgxaGnBnHoKpvFfEa5JkPZEIBFszuppfvzpHMAs3vLgxZ2bw27uc.qged6.YymOube6VeFWyKSmKetsac9PA1M3kH8ZqU+OGppIKxNmL5jInf211mwlUzH9xACCuc0ECq2Rw.c2FteIA0utgmmCZsOf0SY3Rogx9v2KEWhYvdsF5MClO1WlfniCqOTEYS1nKD49a5Jka46FjSw4lGNmJenbwLLRWfcwPXfADiwQNZMa1rwqOnATQottdGa2Z2fDmqtDamIlAPUSgeU8qCzv.BBhQtcI53pAAHNpq8NnCixdCtd9F.r08800.U6w9.VOSfsKIb6Q3WTrAkVOSWnh6sbEkNf2qB6tQHJ3VlW73Cw2rhpnRpOCoxT91k2WW1I8t6LYxjhq3v4kK53iAw1V5aFxZRYnw2691LW.stAhM6beCPDmt0qAO+Pxoi5ZI6J2wMoXVrvCUR39.VWew9.VWww17t5gBnnBYxzgPWHvab+SwF58zf9PIBA23jClSvF5KjtyI3Ean2HHmqFDC2OoTY4pO3fC1szzddNMe97cBfZTJSUY2.XC+9xeiiW0fFa5CrYE0evchB3cqKRGSelf.H9422amgE7vK970wRl1GDtf8ArthiKUz91Zr1Y2HqPqTycWroLwOGHmwobBe.goAkH4y2IQuvApsav9Ea39v8+P4fExjV9OyLDDlLYBpVTPgRi22NXw18IqDjzEqOnVEVUElAd1FOgTcCImHBnWXEkTBWBWz1cBpWmw9FuuOf0Scr8piLDLXan54lYp6mqy5CesyxT0TSND4z0YLDHan00kfclifwg00DMinV1SvAIqAXTSox474d9mYieeLF4niNZqli22LdblMYJPoWWd+sY41sbeu8s8nVdgfWUQX57w7vF9cA2wZ2fkJkE5j6ox.mueiddbBit6Lc5zQ6pea8B651I1Wb8rddD6CXcEGWruUv1i4tDXH6BlVgoQTYaYVwv7DhazTIH4N7rwfYjdw6igueHH4v2Oa1rGd0W5Ooopph4SO.DamamsusQB676TUIEh3Z0XC6K2dd+5.kwScHtgt08UIT2Ey3TGOd2iq+X+qxOifgljewOcU6y7vbkjGP6Ubyc9aEi4MMDwGm13kQEfwxx1J.fHBGe7wiJ44n9c0OwRUibvAGLtbzWL3mrcvJWALPUrPMTOojs0Vk5nphm6vysE17iBWxTH29X9xJI7YsU0YOd7v9.VWwvEWZ2wIto5ir2M4bl1jQxLrAUMPNmaTAf55HAsXo8C2tuSLDenzyCN3fG8waeIYucja77fU8+bPwz.glo67ncfLqtkv6ZQEFWF6BrRux7xealx5LcQZMr8yQ6w0KrOf0SYHW7hu6EW.TonDB8e+.2s.PEGwbVuJgk0yKspm7lCKbbUvIDFxbZHn1kyNb28wdQUUUQSSy4+M8xS71+cMMOL8Dv8Ko7s9.vBXRf3jojFVUGFZbufkxj5VgZcCOJYnA9R+e2vzCUU2Q791Gj55M1Gv5JDtTYrs++1Vum1dAXGxxZ0pM3dgx..6j0QrpDfJbgV5+nN4d6rklOe94F5vVAz1N.QccM000OTejNuLt9oOpCG2BIDhMyJRFyV2ttWxXLk5JpyfCXkfzhVJoUkBGrb2opphpppK83eeIgW+v9.VOifG0n6EunNAsqV2y76KRQAX5zFJ7muLwt.kkhNy4qhykUhXLF4vCOrTlpUjRFXWtgMLAysyB6x5yz129Y2I6Bw9IYVJEzGClZlgk6.2JjE8BbQaXqeb2GETvsOt2Gr55K1Gv5JNL21I6lyOwsuI3VY1ZmkxzFB6nfAh4LUDNrplnTVxXr1dMkRfGdyb1YRdwXbm0wY.6FPpnIUCAMLjhpOPnzvcuLcOSnbc8+6MDHVSVhH5faRWD7OEC05PsgCvxuyEqubvs5CW37ueeOrt9i8ArtBgg..aeQwAKScroTZTOAv0dcvJHQxRjW8rkbVUjTTfJg10qo1EZ1zxG6finxS3VKHcX4MHtRPpwcuOimxN9MzWJwg5XEymNabphCADhw3nf548B02AGMmrKjSNnARCSMTy3dFQBzkKAbZh0zZFwoG.UMzZkxFCdIPUkmncwcoRRHVorWCmrYnZrHrfTl93zoSenMA3xZB+0I77bv38Arthisy34hzEnz77hyH+VqWw5PQIC5GiFpAyP4lSaHfQPfsYetSQxVdTu4eHXviDpf3NNFSmNsLb.UGyvxbebQqM2249xQQqKYXYTL2hBkKbTwv5VSU+hZKDf9LoxraVT64e0yWX+q1Www1bi5hWuCXtfGTty8uGtVT2AEAwTBtRk.27viPsbO8BBjEkrXXhQtmI4vtxsK.Gd3gOTi1G6QznAOTtLa1Lhw9R6DCBO7NDJh.ZQS2yHDqKSWzIi1qjpCZcU6hETImOUw.BbI8l54E2x440LptH1Gv5YDrcIYaeRaVAQCb+kOnmU4FZ1QGVcktVN7fI3oNvbLhHT0SOhDvkyapA9WscSru3E3bwzqpphI0UkfOCkjIVIqqPYBeCAsxF3DIV0.p+POtTUoawJp5usMouDXqvmqs6aUcrZbUbdVD6mn46NrOf0UbL7F4smDVAaIZdBroqE5mflzqNmBArbGGLsZbBghLni5koFVTzyGlY3MMMkx7daQuJfZBPQBkG1GwsCBYac6VlhohoJZUcQ.BwfbgBClTdrl2rlncA1sy47Ry5cf5AIa9hmv+rXFIWVfqmEeb7AI1Gv5YDLDv5hMb0PoM2uOgbtpbZh1yxcmI008ZGkMNcwARpB6xqps4e04Ti3gcwmKdhjY1VSTrn9BtJ3dg.pt6E8kmxDBCwIHwF7fhH6dhZTUjTKRt21wtPxSaebUUU8PGm6yV45K1Gv5YD7nZtr6v5UsfDwxxXOebUvBBZPHDuvIx8jHcfY4amMzvkgfOWJYVGab9.K0UD2X9zoD0vnBMb9eW+TOEqHyUnE4kQhDh0H8lipz2yJEmPpEeypQIvoW6UYa2EZnz0G0w4db8C6CXcEGa235K1CobuTJupyPjphMxLLItdyaHhSbjfnxn4NLX.E6tqdmi5dRcdY2+CX69FUX7djXrHIMCkZht6JyXl0agXUjcEMFAUGsyLw58xGqCOsozH9s5Wl693zD2Nf0d77A1Gv5JCJ63mLJww5NWmpfpEtOUBJjJcgRCb+UKopdFXCJrP+xOasbx7onaZI385yt0wf4qVVCF+bCsnmCSwXj4ymWBJly6DzZbhhTnTf4kx7F92Mx38KvfdK2UBNpReYr.wJh0SXcaGln8JMg.VFI2V1kvblpfRaWGRPGmKo6NMMMDiwQM65xXr+yJ3x9PiKaJqOpEV+4ErOf0Ubbw2HuirvDCrRgGroiNSfPEiK1rmPEiaNYBy.Bi2Lkxy7AWm4BRIC.ylMazKBebHo31bEa5zo8McW1YMgJOVx8bcuziMWCEscWCfDJqJDE1wSZCVZEhkGaF+.q5EwQ02dJMruDwqmXe.qmgvC8IrwJVKJu1hyn0cTsBQJJQJhQz63kOXFyxYBIGwEbsXHoYALcWFhObaezQGcoeh9keLAZuj0DDki1hJDlWZX9PfusaLt4NRrhplImKjeVgPrJf20gztFgTu3.5mqk6835DGrddLao2KXe.qmgvND2zc7fRarhae5BR49URYqLaBdhWZVC0oRIgi+60gKgKMSjA8uZ60bYaLPbzgud9hUaLe9zw9kM.Esz6LOOxGqxCHEI1TlvoCleNi1UqCO01yN+dVs66NXfpGQ+q1mc00WrOf0UbrspHrSvJxjLmTrg6rX8XCxcWvKzLGEiaLslJqsHuvxCqFoWjRCUUULYxjK82cYGa4smvHN000i5O+vpC0+GfThJU9QARFDqlRBE7HPYMiL.wSPdCtmwHWx5ZmiAk5pIuu9b8SCrOyp2cXe.qq3X60l4hpNZxbxZCKVWXrNCkgskcndz75hxGLJML8ShyYGGad.SmNcrA1a+61NH2a2IYgPf55IiKm7Emtnuk0ckcnZ1LLOfqghNMzmEklyj2rFq2kcDorxQnkKJxHoQ2eR+yOXe.qq3XaEHXaaiWUseBdJscFQMf3Ff.h1SBcmIShHjK8sx.5U5gfyn7sL1yIyF8Yv2oxpFkBvdFmWhYTN1JV+UgE7AIBlLtiiCF25fi7zTOAq36Wkda0SUC0xj2rB.rczAGmA8Vs5ZTOr1iGOrOf0UFLnUn6BoH4lHgHnALjcx1xbgtdIXQ6sVqykmlA0FM2mkSdmrUD+72.LjETcc8XvnsCZcokDNpvUZ+OoHHzTUWxtBqr2eh.8N0iOnvBAsjIXcMINemDg9E3VJRk7fa7n3P+iirakms1mY0ycXe.qm1XrmTfgQ1sdcPPXv4icxjcGINAWpHaJdNihylTGYQIoBsIiZUgthVnq9fLtzfD5yTQKYSEDE2RXoLUg.dNSSUUw+AwIYYz9dQMvSqcV8E26Wum97l5U6TGgW3l2.K2QN2UrzKyQiUrouDzjk6UYhHd0LRgFRhOXAPPpi5PMcq6PLmfaDbCrhpN.fDJzfXfLoOK2n82NdV8nV77m0eL+dE6CXckA1V++BJmaVj43hwMTRfx6oi.hy5MaJbXxE.mXTKpKZJSrZWuLT2tmR8mWDiQRoROvZZZF6KziqNSc9IXm22LUUZpB8qXMzlRiY14RwVxDQH4NU0SodR+jEsLQENb5DpDiEm8.B8U3BPPB3lRPBXcFRukkccDOtAjddKv09l.bkAZOEAF5MTeYRlM1j4ARWd9N5Iz006hyQAhUjjLVvAuXs6AEhtCIJYLINIyIpEhaNlwUHLZ3DlaiN6rv6tlZKTVH4oSmRWW2Nq2SouVfksRogND0.dWBusk5FgTxocyZxlQvViJEYf1bEUpAGBZ.yVO97w1Om7rHd+Hfya2NedcB6yv5JENOKkswPOkJtNyPlXNNJIfM4bQgQqqnsaClkHDBDcgZQPwJJ4oq8bYJiKRYG95eidUU0ngS3tOde9Ngs2mvskBmAooYvaCGLahQhiZFDTpZpQ5WqmbNS1Mh0ANXRMsqtOAoeiIkhn+MXdXtLzeumsw6TvpuSJI75XlW6CX8zF916M3Ci9tGAXDjsjXXurdKKSIrXQEO6uAKxth6b7zoH7vly..Y+79RMTh1rYyFmH4fhh9tYG11dOCG1oPwcZpp1oOXE2c1PCAZqDVDL7ZAK3jEnM0ARhtMmgPGPBhFcVGV.1j6vBYxR2a6wydb8C6CXcEGi6oGkkedvQmyFXZf67fEH0SIgi0sAoplfpHcs7gO4XBNX4xsiIE2qQ0HVJiY1H8BhwXgNBRYReuizZ3BqyyXC46+ulllwIYdQSgXjVC3H0SwjJZWmIZ0Lq4FDkYT0EYl1f2tAwS3VFmthBkRlPn37ynOamEwiydZ91c46ja6mEw9.VOkwtiye2y+r9.BCkoEBgQtJkLHIAd8G7.VK8S.zchRjpLTm53kNbFgd1l6AHSFKW14OwcBhOFr5jSNgftq+9cYe+Ewk86FxvZnA9ccc6zD+AGktqKyx0c7hm7Q3D8VDdPMKdcmMuohcagS3FnqshTI21RTJqriJkkn15RWKZ5961.QePca7r.12z8qznOamACPUbD2vcgjHjkH2acKK6xPMPnm6RYiYhwrfRsFKSULnjRcHtMZs6QsHaKylMiacqaAT7AwBGpDLuTF56DtnlYIx4tA850qoqqiloSIkRiRVyzoSI0l4342jWssheyu5qg10gczsPPw+iecl5uAeNKvgn7.2QTEqmk9VxoacGWW+L2qqAb9NE6CX8TF6jICBVeJVFza1BN3JpTxJQUkj.ZnBWib66dFdnFoJhmKFKp1BUVhSlzf3Eu.ry50Zc67LbrTYJdGe7wi6O3vTBeb5a01W2E0gJUUN7vC4t28tzzzf3NXE4RtophTaKSiMTklxu2W+M3E9ree7W7G+GmY+P+vvcuOK+Y+43ex+j+Y7JuwoDl2x7idQty5NZlDoFgtMIVc5lhzyrUFnuS6+3d7rM1Gv5JNNWT5fPPJSJzfrIfVyp1LnM3Iu2IbDxjoQUNbRCRdCh3DEESTBZnThVUfVKOJVeEIewJ8vpuLzG2IEtcepFBVLPShCN3.N6ryJAsjy6MVWWGGqUzsHyYqE9I+672lY+4+yCyNBdEkYu7qvOfI70+5ec93u3Gkkw0TM+H5RaHRIf65t1x.CB6Z5E6yN45KtdlO8yPveDqjiMtdM8hnmC49RpJq3RfrAaV2RPa.I.w.VvK8yxblUWgXIv6PbsPqA7hiMqklVOc5TN5niJ2mCSx6wno6meb1y1b3gdbbvAGLpsVPgjpCTbnrJQAt2a7Vb3sdIl8C9CAm7RjYF30vKeBele7eD9M9x+FbzjH000nw5wl0mrMrZyYzkS6yn54HrOf0UBrk1n6O70NP8fSO8AECdPDBU0rZSBShnZQZVHkJ9On3H4DG1Lgf33CAhb5sgqxWCg.Ge7wzT2LlYhyV8i5RCk9vXHfg4mSRzbNScU8XurZaa2I6pppJ1z0hzTSq4PxgrQnYZ4AdpibZMGbvDZlDPxIVe1BDqvleI.IqittMiScb6ik8Autdh8ArtBgyOG6hjwToqqi0KKpWPJYfFXcaGscNa5xHRe08pRUUEQbp0sHoILtVLUUUrYyFpqq4F23Fi2OgdA8anbv2Kmzu8TMghcg0zz7PTZPUEpiT+R2huwq9GxY+7+RvCNEVcWPZg6de9c9+3eJelW4CwCVbepwYhYDrLVWKp.AUX0pUW34p8AqtNi88v5oLFynw7diBc6fUBlKfYrZ0Jbujcw5MILwY05NbQwcPUu2PSEpPYdUEpkKZHkHX8tWiKPPh3oMbvzYEylXqLotH+pd2fgoKBLR9zCN3fQyhX.EJMzw7oy3dm9V7S8S8Sw+m+896w+weyWko+E9KA28sn8W3eEe8+4+r7g9q+iVxHqIBaJV.VNkIKfnAVrXwC4dOON510d7rI1Gv5JIJ8t5bn7fGTJGTphDBJs4LO3rVlL+.plLkTZCjSPJhk53FGLiIwdW3IVQVMLOQrWGsZhUbxw2fpPrnLCCkTwtkE93fg+Ma2j9fFHaYhgHGbvAb+6e+w.KpprYyFVGTZlcDGc3MI+U+57a926+Et8+8+c4ibiaP0c+17xSfl61w7547GmVycc3HJ5.e1CjbiUaZ22n8miv9RBeJih0xWxrpjckh3m+4HCZA0pyVPaaaoGNSZnMVy8Vu.IsjY1obb9Abjtg5nf5INpQftyPokpf.VBOk6Y4dgI5GdvLbOOlYTdaA86wbJgWl1YYC66Xe.padyaVJSsuo6hT7SvEsanqogIGb.enpoL6O51741Xbqu8c3U5TdwbEg6sjIoxp7b7MtAIwoMaPHhYPNctfFtu+UW+w9.VOkwnNqKYbIi3BhIDbkfCAA1rZEot0TEJRvxoaZY8gGyqsYIxh+XdgUeK9tB2iWd0qwI0czTa7J25.z16SkrlT6BjjQszfjCDHvw23FLY1zxI2Vow7AQGsvdw4wjTCEL3bN3doLT2oJDA2oopl4ymSNmossPEg5ISHNogERFc1bNZ5wbPnlItSS.V0sBOabmu4eDMK1vjUYBaRTUWiodQqsbiT2FVud83wwEIw5db8B6KI7JATfBqscnORg.jAWYypkkrqhALAlHBsKd.yesuIeucuEg6knpaCe9O7Gie8+fuDSlLiO8weDZDAOaD0JbBHt1So.om6U8SW7wbZfuWvPS+O4jS3t28tizZvcmj2SF1I0b3Imf7sdcBJnlgPMtCs28AHKWR7DnaSKI0PqhDKJlC4bltttcBTs89MtGWuv9.VWAfKPuH.Stmb6HklvSxY45MjTEhAxBz7fy3GPMt+e32fW6a803y8c+o3fO9KvW4a903i85a39dCe5ez+bfGwrY8NzbW4lM.SlNkCN7DJAJ+fMKjg.IGe7wLc5TVsZUgs98bJyDAopl4uvIrTbZ7dAFTCHl.qWiubEZn2p5MiJQwshgpNj0199X87A1Gv5oL1Z9b.T1ZPAJEJpXhw8dvCvxBUQkMa53OwstA2+K9yyheyeQ9u5u0eKN9uxOHLOxOZmwe3+jeF9o+E9UX9c+1L4nOMJQLWvTCO0QcUfabiiX5zFZyF056umjewRwx4Ba5ETtwMtAKVrfXLRaJgJAR4LIUo4jav8BPmk5W.7BYYmgS6oO.08xsSmgjLRoR1YoTh111G9408SJ7ZI12CqmhXW6hP6+ZFu2G9DGRXrXyJrjSzTlQE+QesuBu4e7uCe2egOCG+exec3k9vvguHbxKwG6+zeBN4Xivs+pbq0uFyjTwB3UkLYbKwwymAjJx0xSpGqtywGe7NN+iqBtnzIBUmbLcSBjFkFLkZohlry527MQxIJ1VQnnUzdlfVtc2lTpae+suGVW+v9.VWQPwAazhSyrEwQeiaeaLJbWxrxIhu3sdA7EK3S8w9nPcfGnBaZNlgdg8Y9DuDx56xp6+5H1FT2JNtbeypC84UGCw21LPdudB+12lgd2YVDYbRgoTZbQkcQw5yvpqJRR60udGhlRUWhk28Nnt0aqYmK2x4bYplWV.qqyRrxyyXe.qqHP.T2HzaCpCYcsYSWQNYvXskHUG3rEq3.NhW629a.sNGHYrTOiuyF+A+t+6nKFX9K9RzkSDDiTaWePh9sTzKpDO7ASYS9flz2qeWBxNZhUPJlDlYPKBUGeDqDmjRQy4IPH4Tm5XycuKMPwwbzhQVHpRtW1kGLQiG54z8Art1g8ArtB.0kgHTD.F7tY.1rYCa1rovT8lJV1sA63Sn6i84323Na3q7u9WDsskosKfbG+69m8ujSi2ja8I97zFlPqWxBIuoknnnQYjM8ePJ9caygqw08oemHGx5JpJtUJKTObFKwwBkoJFIPzDhcY5N8TzbGQJYrk8di43BlK6db8G6a59SY3T3ZEVwUSEyIpA55Rz1k4rkKviPxSDb3viNhe+W+Nb6O6eZ9M9Fea9k9e5uO+m+q++KuPLw25aeG90d0N9t+A+Qo4C8mlS6VPb5L5RFSmLGImNujJqXeVCUR8dkN.W7uz242UHf51Nwy4pMZGwXDqqiPSCx7YTciivWdmdaYEp0.0lvq+p+Q7gSITLN2LXK5EOac7OD3ZPMH1iqeXe.qqLn2l46+hhvpkKY850HQg.Jhk4tu0sI9xuB+J26M4a8o9yxKGOgu33L2mG...B.IQTPTMAh240HdquKdch7Qdk+T7MVl4nI08VgUlPnlUKWfVWzxcITDyu2UrC86.rcvvc28u.lmvlLkvQGR9ae6dqESIkSTC3KWS2pyvRaPqpN27YKqI4i79ZOt9g8ArdJiwjqB8mjYBjEBpvCdv8HXfsoioUAZaybyCNheuUNekUS3adx2C+gG744W8d2kOzG8lb18tKG8glvrYS4ScTMGx8wyckSvIiK1XYfYJ8XZHalOHw1p+v1Y9LlQjFHOqgo25V312.EAWgTts73e4F5VtDRIjZeTrAC6yh54N7AR.qKyVo1iKGk.GN0ReWexxPG34rkK.wXRUCXcDbPRPrdFuQaK+QxMn53ozY2fWc1MX5zWlIO3ay2+q7Qg4OfU2uk4TCtSWtkpl5dGzIRtXKfePyazQsge6R0F7nvxpKpjCA1nQZtQYRmUZfr2hiQ.AMYjWsff00e.+3pEpW+wyamq895GQsm6Ku6fA8rtxoCkLJcUPJ.sXrIsgppPQn5DGSE1rZMMUSXSqC0SnayZpNYFcatCaVeGN9.gilor3t2gow5xj3z.lVxjwjZPpH5cDvP9fNhUOtLw.L2eslprFm3AG.pVVeGOgBDEkZIBqWSia87wx5MEVcmAGbwSXed68hOOb929bpeJCAi.CuPTnFoix51Ujyc3pSJkPzHDhLa1A7fG7fh9RoJXYxVBHyr4Q1r79DsDyiSH5Uk6ConiVssqwEkr6kRPs7Nb95CrGia0P7s+J.VPHINqvYxQGQdXfotgHfgPPD5NcI0.XEtXoHH48rY+4MrOf0SQDvn1yzfQHW7jvnqDQXyYKAKSa6FldvTbWPkZ1j5PUHJIX48IBHsFDqXcqQiD335CYldHrQH3FA5nxLhtgPKHVOy52l.EevfskolcZ3t0SEAUn0b7Pf4mbC55cAGACUbxtQW1Y4cuGU4ckR5PuV2eo2uWyyz34UrOf0SYn87uZjtA8svpc0ZrTloSmwl1DtIzlbVkE7pFVr3TppqHHZ4EwPEgPfJAlDKpz.TxfSMGqKwj5oDrhtQ04YLMriQt9A9i099WctS.Uty6rLVUEwCNhV5kqYJxri4Ehg19fSo1LBWLNz6y6B4db0F5i5ShdbpG9Q82r+S2dbgBZ.DkbzwDHYY.iGbu6hmKllp6BfRHzPqLg6sxQqlQ2l1RuofBq0ScnrBiSQlZzoEFfGzHtGHmDhdEAKhHObG2+f70M2KtL8f7xfJHCFCq5rInTcxwn0MTVRopxiofhhwha+ZLIkoxEDWKqYTuAylcCQ0c33v6zp4bYt7yUYLbt1Eu7nb74qq8yRg292ndc7A8UI36boj8g0qwSCP0HEC5JPqTwaspkDAPKC40EPLA0blWIDr0jsVLwJZBeoM0.JtqEpS.vSf9WsM1lKVikG1GHqKFPlMgp4SIK5XopEEWEr6eFwUaPRaeL+j83+oAttF348JFKI78yfV6aB56N3zqRm3Djhdm2lxnUUEJ.TVgNxtSWUMu9omUxpHFGKwxLH5AdoYGvzLnoDgdtOkoj8V4h2uZN9SDpALp26a8I+CRZrYEWo1cgjJnSmxziOjbvoaL+Inwc5t8cQVrprdO8G36OQ94OrSOr1aSRO8fz+epnrd8ZRdQYM65E5N2cLE5pi7FmcF49rTJSHDPTpj.uxMNhCHSH6DjHFNled.qgWY0A0g3IvK06n268AXGxbR6WJZODwmzvzadLsAnKzGXxRTaN18OE8rkDoeAnKOJ14CGe2ZdFWkwSyLq1tjyqZ3gZ59aWOstHdmD8+qCuw4IIJuXXrXwhRVQgce9KKPaHxc2zhogwqezYkQ3CcvALuKSiIDkHfRVGTOAqORUOs.dh8Ha22qL5vzhf5kEZ10ZZUkIuvIrIBoXwYpUDlRfIq1fe+GfX93swksufWEOI6wEuWBT7N0aq2K2+Wkw6poDdU+Ayyxn29QA2KdsGduKMWDaFI.YQYsF4zrinQ7bFs2EZPBHdlazDI1tBM2y2IoPcgh6333ZQZggmLudtc4fa6PyCrc2cG7h3E1YP8sNlyzLsRoT1nFnBmoYm029sJtas6jG164qISIb+4VOd3QNkv83IGF1ytg98rd85woosCIKwYcVYioPHd90K.hAVlChPHsgHNtetq7.8hDXfQKw5I0o5aatpwXbrg6hTxhxcGwURHL8EuEKCE8+ZrrwNiIVlUu0cH16tOt6XawuqKiI8Oqf8C85wGuiSIbOdxfwA2IBoblpPjf2KGvlg4NcNzlURdEZefngdBg.BYpCBAxExg5ic5omnkkrqFyv5I7iQAgXLNpgUkGtR+QX.ITQ8MNl1XwopqBBdNSN2Rz.a4Jp8L0gmu505yBkp8jB5ihGGWF1oAmWRsxOt2N6w4vkgoDpk8Jz64pTWgjjJ8LD2SXhRmGnsUY0l1hP3EBkf.RFgVpBFMMA5xYxa85SDGKkYRUMUUUEZT3O7qSeP2v04ymuSliCbyByvLn5nCYkT1yvAUYX9jIDxFm8VuEw9rtBx48Caa4p4hOVtpiKqeSua423E+6e2XnrW1q2WkedaOS2eJiKqvLW1xLS6Ow1EAyg1jho0nRjbpHWKVWGQKwD0PHg4IjfLxhcEPEAUDlTOsuLQ8IBK2unM1WUU8Pmfp8meXhfOcZYInkRIwYJZ4tjLdvseK7t0f0hF3QFnZOt9hmXArt3TL1iKGikFNLzeQJYJETxhx8W0QVqQCMfYHTgkyTYsb7jHHIRVWeyseXlrOa1rhc0ynpLeoYC+9YFxa+58jIS1YsbBhW5+FfoBgYGvra9B3TLYhLf4N0nr312g75EXcqop2xNtNf2tIv+3T0xkc8WWOG6IR.q8quyiGbd3f4CuQ0cmr.uwYKIEmfqC9gkhXNMVGu3QSAKO1D9dY0pXE88ePwrYG7j+w0VOlZZZtz+FihIxll1vzW3EJO95GDQHTQiVQZ4ZrkKPa2.8kNecAempqUWrjxqq3C7.V6m.xiGTFoHE.85WUYZZAQJRMSHv29d2mMg.cNE4kwEBHLwZ4UtwgH4bYwg251pXaVEuIroYJ35NzM3CRbw6m555c+8ZOUK7LYA1TEYxK9hXpL5zNhCpITkA6rSYp.jMTcuf497F12CqqPXnuUv41j0NMnVEdiEKXcHRmkQDE2EpPowR7BylPn2rGBNfmQJoXApPrth5559cDVdhQczwl.Sw8lC8bGaaswx8LRPYg.M25DjPrL6PUwxYRohhq1duGvLDvyX6+.um6v9.VOkgPefps9YnTdTV2c8dMAN0RrInjYnTQgfCM4LGDJZok3JhaEwh2JDvzUgPcEgndoF2vGrOFKS6CfXL9PbwBnT9WLvREpuwQv.GrFkdGkJQY0cdKpSckxbG21vm8w6lRBurdZsujv83IBbTbY2WFJYZUZK9.a0IDwHRxCj64fU4D5BgQUqiHYTwKq6hHHlictOXUBTPujw2yr9yo+0k+l+uSwPVbi7tBYLCqxOGN+2KBchhN6fh+Dxf1XoTEpH5Bo6eJRaawxudNj5LOuSWH8hQpe63iwE+Tf2MO4seJgOLbJlPwfxeNrFNtkH3Fj5HacnwJHTylNvsHXAj.EtY4cHZFy6noIVLsgdly6pWjXFxnDX9j48CNrbOdQ8b+8C9yIW3BtiaFQMfhfkyb37CFmvmXBpq3.stiKUzL+.V5szJYxhT3mEJZxXyomRCBUDw5JYsMXg8WL3XA16vkqd3xNO6wcJguWDvf2tr0d6NFeZbd7aaFVuu9Ise.8I3WGPeWlJj4ru2UfWXmd+jvZSNYSv8.t0+bX+dA54NlMsB7LJE2U1x8qfS.bs7FxYSlxvIp9kDv5CBbYmLTWWOJaNr8hLKBtFPqqIKPRJ80xnzqNEg7omQs4ip7fPX+6mtDbc84jKUdY1imLXf1ACx96PPqrbdfqnTry8bxImcDJi6u3.Nk9ZopRvLp6su8ra35VDGs+1e974OwLN0KhgOQVUkoSmtyZCQp21uDkTPINaFUUUERwpAZwnECQcV7l2gIc4RS2kcCHdcRdYd2fsy1459ic8cSYZeGWtv9U14gPozohkP.aSbzcWwhrDn05U6fw5sD.mpPf75kLIT5MkHBw5Pwsc5aZsRgCT6Dn3oDFNN5yOZb4msLzIBwYSX1QGPntgDNcXz02z9k29NnKWil6eOqX677zdb8Nn09lt+TFxVmjs8KFhH63RyYsh6sdSQirFdCY+WURbTcjXW2nMXACMrNPvJkVFBgcOo1dBHuL9Cy2qgrmJAeGDu4.NAxBnSlvradS5Dov2LIfQIaSawRryVRvxiYNNrP2tW5HHXa8856vk83sCuep2VuefG6Wwdudv83tL0Ouhgx1FdlPcFI94.LQoqpgW+AKIkcvMvUjP.vI0sgW4kdQ71U3VBSftbBTo2UcBLaxzhJMnx4SN7IHtXerppJdl3.0FF1uQj.4PfYu3sXM4RYw8zfHhPskY88tGQ.UbLKsu+nOGg8eDySY3h0qw5m2SqResJpwYFmVQXYrgW6zEzZkw+iOXQXNAOyKe7gT6VwtIzhYoBmmgyrYyJ81ZKqSUeBcx8kUpVUUUgXrx.8DFLICgDNydgaw5fPxMpk.AygTlFQXwc60EqdtlUz1qGdZ2OOE754kxguz.VOO8B8SSL7VrKNbccPoFfheDBrQq4ta5HMVmni6BXIlDCLgLyzdkkpmM4tWZTOtSccc+ap25d6Ivqya2eocJUs+3qTwmVzcdyvEHoJwiNhtpHhUxrBJArpcm1yNC0JMd+4kSTebvyCMd+Q5ZNWbaw+NAWllacc9I02sPnv0HnuA63P1FaXdrplknb6kaHDintgFBXccHp.dhaLqlZxHdQNVfxzC8rQLTSSSoDrAodwce2N7+AHtrddLtDzpf0W5WHFI6Pm6zbyaw5gBkaaQwoRfXaGc2+TrzFhwvnLyjs73s+.MIdVMX160yOduTZ7a2.KdTCi6o44t6KI7oHF6a030T5giDzhC238dxGJV0D73DL4b+5CUwMiJANrRPysnJHpi4oQ8SODBzzzPn23JJ40nOQxvZ7X8RttgRgKh0mSaNQnJRmHHymSptDTavcqsTlYdfzcuOUtyk3AE6w6Q7ndM5pVhEiujeU6.64Er8dD5PYkTzAiinWf9LH4UzI8hem5kl06NjSDIy7pHR2JjdyXkrUJOLTQLFGUIgclM1SfWxeTeB81NdSgCV.ZO+xpZPN5HzoSKKEslgP.ySLKCqdiaijaw7VdxKzyevf2oy+dm1TjmWN+8J6mQcYiR85HNeW95cSFuDLZnLJEgT14rMcz5ZOmkFqerv1aKSSDTOWzCqsrQKQDzX.z.laEIagyKc5oADoeeB6e7ToALKQHDH6FTUAymS3FG16MgYPchhRUmwx27Nvl0Xsqeh3qhOswd8j6bDGj2iqB3c5335bSEEov2J2EvKAuFxBwEg6uIQRCjs9dToNDhDLHpBpknITF0eFHpADu3zy0SZ5ULggz456awSnmFuro2EiEsrZPfAULbubnkEk1ClP7++16r623H8J89u2upp5tIY2jT7iQRyXMxiWXud+ZRLVffMIHY8M41cAVj6CxEAI.I+K3+.BPBRtx.IAYQBvdyhjK18lcyl.jfjKRx50YArc.h2YGa4wiGQwOUy9ipd+JW7VUwp4PIYaIRwVpe.HjnnXSVU2um94bNOmmy1i.iffsjPL88DqlSX5bjkUnCg5zZk0xhnUQsjdu3K0jgqDudeO6Wz4uWzW6U442mmykda4L2sFFV+rbS+1R.1WIPjrHlHzVj8lgFVQxBVhJImMaFdoJMEfAGDhXzlzhkHyPzUhQ0Hjzj+s68d7dO86sFA5r3QqYwIE2bO8e4A5UoRCCsLB37nkJbVKZoh4tJrEEjcmMAi.IQBgTCED.hJOUSNmLAuUvv50ItsUGqaEArdiJ.zOCHV+gqScXzHPGEnBj77oZFGO47wTJEfRlBzDBHCQTBA2YqQPvUW+pDihTW.SLP5s1f5G8TJg7ZlUc2ZXIhoNYJEQDg5g2NJXVlhr6rEABnDMLwBnp2GiyN9DLtP6HMsBucfaEAr94AuYDjKPf.MKgAgfVW1LJ.mH4xn1Hbz3YL2KHJyQnRZpxamRgxyNi5iRlLqOQTfTpSEsWk1AfYYZhAaqQ3Aozw7uFV+nWNECYThBU659J5sHTPoLhdi0oJDPHTolO38IExG7TdxYnlUh1uHKqVGu3F95ZYEKamijvy1yctonBd4eNOq4W5488rLhzUfMkxCMDhTHEZbHvoT3UBbZEG7zoDy1.urOdmfjoMLirvYr+HCYxZQhZUno.uPSUvS+AYPnBkTTK+RY874kDLw0MdVdnVZ1FM0qpLcRBGxzlvIDBTE7Lbu6fWYnJjdbLZCkyKwDETc7wrlGx8PlvfDAVuGKApDdBDRihTCM13E8GM8azsGlY+zb96EcV3m2yuKamitUxvZY6l3KCjbwhTPH.kTPddNRshnLInTeTvbu.mp.qM.pjUGmKCTTMm0CBT9T21jcbvyjUtjiQqZ6NX2kSwMx0WG4Kz8flwXPqkDTIVjdD3pyhEjDkRj85y7nhnNGsJmRmEsRCAvcxX5ESZzx4qR6xQUcyJ59x5tuTZ4hLwBX07Rlvsx.Vvm+Ik2LeRRlRcCIQrHDV.vXxScRSnQZACFb5brJEHAovgzURVom0mlyVtAj4zotsoi37okMZlLxFCVCcsfQaXanBfhPZHquguha5pkVqAo.mvhW6wqSdekTnAoAqHCQ+gn2ZSF6C37QTXpCpEX5QSnvqHJ.qHhOFI0mvPxW66lt6UdQdq8k9qvyA2peV6M8w3I0z8jKEnPUKVTWqBtUBIkkUXqhDsJnzQ5TYnMfVtTPOkBoHRz4QqhXsypcqTCE4qg.MwPZlBApGRwaFGw5pRgoYzYDJvKCIsVIuvwFDRMnxoXsgnGzGuRPPIHR.arhbijpyNA6zIT4qf7jnRkPpgEs2eu5fVBtvfjWlHc8l7YgeZwsh.VKaE96UIpmXyjM.iBmLfouDhRhgTgyiQv3UfUg.ERcFVmBLFBFKTTgKNGoJhLDPKj38QzpBxx5CjXh3qKiST1bX8l4o+mkxr60qGRsBGtzbM5.myAHIHzTzaM5mWfTEvKc3jUzefjn+bN+veLZeEUt4jUXHfmPvlXvEBcLnP4EWm0ApW4GVKu309ln7s8fURR0sI.0LqDnxyvEc37.YYLc7wre4IrgViexonJ5wwdChvLzpoDMNpvgnHCqsjbilokQJJJvXRAqPHtn9yhHwPJsoq64Ir6Pz251oRIBgfQiFwQmdDdqGoJhRIH5Sd1UkUPYTx5aMDqL4IVkUNBHwZKISAB2bTwPs5+qmQx3hcMroz5Kq6H5mmvPeajs0q8.VcwOKOAbaSAt+bgXhakJ3g50ZkODQJRdEEJAyhAFZB7UO+6Q7S9exGt2HN4r.+2lmQ96+AL2VQLFwZLLkJjBOFk.Slj9qaZDvTcQ2S6xuD6CGWDx7lU.oMOms9fMnuoGgxofLfVovG7nUJlYCbdzhdTeb8MPk.Yzv34ND85QtIiwGeD8e3C4zymflNApjMWWWwA85WtHW7SWgkDbqJf0akHFqKjdpdKAWrtE+PgQfxVwg+EeW18vuCm+nGAmrAwIU7v02iY1eB8em6xFSNlBUjoyKYfVi2EIOOmd4EICBLlLUlPL4JBBD01RyMwk2hVpayaz3bNzZMqOXClOsjPHRP3v6cfLinVh2HQLLmizAlb1LFs2cwmAOd9YbzQmvuxrRV2X3nISP2F4wCBUZxA5zTg5o9YEVxwq8.VWGVu7RCZhYHD3Z1hwh.EY4o060YGy6M6b9I++917qsshu9eu+wr6W8WAN+b99+I+m4ey+5eW9Md3eW9.2wbreNyiQThBrVGat9Vrd+sS0FSjdrSCXsDOf.IRQ5Ou1uLEhEBZAWr9xFrdeN9TIgpJLZCQzb97YnyJPXjX2nfOxX4W8242hu5e8eSX35b5m9I7s9C+C3S+geFiN9L18AeAv5SCMsPfK3QHk06dwlWmzXLzxla8KM3MhWq+JBu1CX8VODJJ8knUJhDHWqnrrjn0wlJM9O56yo+e9V72+e1+T3ctKAiA45qwW527uF+1e2uE+ke6+WrwG7PhauEmH0D7TuknEXxkIy.rEK1Yv.W+0144eXKvZq2m7BC1pJplaInATRTRXlaNqMZM58v2iu5+j+AvW9WCpbLJD3q+AOf+8+K+myWa7eS1VoHTURTHPloPHUTYqnvj03KE.KWcDbEtZrpMIulPJUoTcWxj43PgGA13b9zO4iIVVR774LJH3K+teQX2GPHaahwdXmEg01j28q8av3SlxvXOld3DBySLY7RGCF0CmH.3p0bEnifN.5X.EdTzrYYt4u1afwnQKUnEZBQAxZ8YEiNb9Rdzm9i3W+q+2B9xuONYEtgqCER3W+qf4di3GevOFuyhreeTFCUg.QjnTFBwEu1DWdaOuJB1RGVEv5FBW8nUT6w40axXARlc9LlLYFY5bzZCOcxD9AO5QokNg2hxZwXzvbGSGOkr9YL2Nm05uN4xrjkHK.WvBhTC8Eb6vUCtrutGioNBhLYoNFUFDDD8A7AKFihG+3mvd28d.ATqkSLCnP.l.Ei5wL2bdxgGBymCg.ZolHQTRwkbihKVzGhaQikyJ7yFVEv5F.Oy1RSffcFJoGUzgNJXxoULYri701jwBEi9k+EYpwyQ+w+GfYOAJODrSfO6X9O869ui2+W5843roDTQLQA8T4jqxPHTXcoETJQIdgDu.BxzZCKhgHFtteIvUM+asAsD.BMnM3bNxDFDVOJW.gC5muFu+69Kve1+8+zzfce9YnN+HvNCrU7oezeI6c+8YvtifBS6VHjZYNDpk7.0eDo6aZrhf0xHTeiuw23a759Wh2FQ5PaDoL.QORogSN9L9rexADQw4ymgKVRtFFsw57G8e72mS9teG1oHiu2ex+E9e7u82i24AuOu6ei+pX2bKbzGWThOTwzoSY+c2mgquNxn.gHhWj3UHZ+nQxpuFgHY0Mmb5YLY7DxxL3itTAyiR5ITLDAem+ueOd5O5Q7tu2W.QQA7W784+527aR+6rEa7U9EoreOxx6QdQeB9HRRVvSyZLqQAZcutauKrpd1KUXUQ2eMfVFF.dQxsBplWwom7Tb9Z6QIC7FMGYyYqeo+J7gQCgmdJ+q9W7M49egGv9esuFegO7Cweus4IOcB8M4XqhjUHYfICW0TDUVPIAI3q6HYVLsMdPTWt8WCGXaESJPk0hQHQYzTIb3zQTJMpRCm6Jw7g+prieBeze5eF+u+G9Oh2YicY7roza2g7K+24uM8dv84GNdBxC9L50eC5WL7BGZ3ycs03.oxZ2VsaWDWgkAHhuMK07aHb4awWjRTffvi.ImcxX9AezOBuOfEOUhJxxjnqbLRqIexDl9jGyC1calLujyDYTs1.FqfYQIYjFxYoXFSm7T9JevWgc1a+z5nWBkRIQf7XHY+VR0EGpuFOy9hVnoUUNN3fC3IGc.SlOAKNJzEjG5gqpj70ELHLkrO4Gi5nyvc3DzqsFEO7dTsyF7i7ULEHSjSeUO9hO3Wf0WaizHHEnivYuntUQjDEMN6vp.VKSXECqqYjNtDQJp0Yt2mrHEp0.UDJKK4jiNlxpYDhQLE4HhZvEvKTbTYEY5LF7fuHebUIS0JT85gvX.efA5LfHUyNGSlhAqMDYVNHjoUoUDzw3EaX4EyJ5ZEW1SmtLxxzr81ahPD4S9zJzxjvWCJGAUjmNdFyHPuQ6QuMuGt6URdu9LMWyISlRkTSud8H3hT5c73mb.Bkj0VaMB3gPRyWNmO42VRYMupUApVFwp.V2.n6g1lfUgXHUmETbzSNlSO8TDJHWaHDbPLh2GvjmgGIiqpXtKRTXPudOhJEAmmx4UHkoMNiISiy4Xu8tGqObC7DZqQiHdQ40ihq8QH7mZDiIU4u81aSUUEO4nCQp.oN4cWYpBzZMUg.kwHkHQojnhBhl9XTJB1zBrHHDb13mhIOKsGFUImL068H0ljjOhfTbg4yrJv0xEV0kvqYzrok6pInt+8wiGyQGcDUNKFiAoTRo01tYYh9.ZopcSIKhPzGfPhsV+98qGxYSKCh0We8jpwujaedaDM+NVTTv8u+8Y6s2FiwvjISHFSqu9PHfs9dxZqsF862u0X.CgP68JkRwrYy3fCNfSN4DjRIZsN8+Awmis2pfUKeXECqqArPK7YwQRwGRiIiRpXd4bd7ieLkkkXLo.Lt5cEXyAsl1vmkkg0ZQpDsGdyxxnb1LxxxPJk3bN1e+8YiM1n8mA2xKQYWYOXLFt6cuKJkhwiG2FTpwcGBg.kkk.zFjxU6E7kkknTJ50qGVqkCN3.TJEas0VIuhuVRCMZyJ1txyVgkIrJf0qP775eQy6lGBg5YlKxImbBmM9os6GvppJTFS6N6yZsHkR7dOVqs0oNSKqgTfuFlWdeZApNXPZC43C91US+sEzDzt68otLkbNGE4E7Nuy6f0Z4ryNCu2W6QVo+uUUU.M0kxAxlkKasHYqCr8zyGS7yR1l7li1L8yHF.Q5Ousx3bEd9XUJgWyPJjIAL1L5s0GPO+7y4vCOLUekN9ddSZcduuccXUTTfRcQZg444okoJv74yQHDr0VawW5K8kRLJjp5hKe6jc0kWZBwXLsInqChjYxXmc1IYaNVKVqs0kRyxVr9TM0nJKKK4YVkkDBAzZMylMiG+3GSksp8ma6yChau2eVgmMVwv5FFRojoylxgGdHylMK0r85kmppNsvt0kopJ42UZoLoVaumxYyZYSs2d6wfACXvfATjWPj3B0H6YsrTuM4mXMoDpT0KJ15Bw2qWujB3yxZYP1ksUddNt5.Vduu8ZJOOGsVyzoS47yOmCN3.1YmcHOKEvuIUvU0vZ4CqBXcC.gPrPJgme94b5om190pppZqIUy1XycF2C..ELeRDEDUtAtnCZUUUjkmi0ZaqQylatI6u+9zue+zFfNFVHUmaxs57KC7deKaI.Pj9cOKKigCGx3wiQHR0sCfrrr16Y.3BAxyyIVGzpIkvl57EBAN3fCHOOm6bm6TKnAQaWZWgkKr5YrWAnqI0cUedHDZSKzZsb3gGxjISZOPoTp1z.61YrtrsZXW3bIILr9f0XzFCQIjDCgZYKHZ+yFVawmwGMiEyqazsv5MHRDmywnQiHOOm4ymSddd68gl.SBg.sTh2Zw4boksZ88qF1VVqMIWhm7j12zHRbUvpkTr5YsqY37NTRU6gnm7jmv74yW3.5yCMLPfTpNMAtLFCvyOktkggX3JWPEjRGNOOmACFz1zgVIJHDnTp1530vJsoNWvE0IqoIEduGqylXgt3R.aEVhvp.VuBwk08TCColul0Z4niNpsE7cWPCcQWYPzsigMGL0ZMCFL3hzndCBsKpBgDi1vvgCSaWmltAdokYQy8wt+YW1sMrWsVKiGO9h6YcW6YqvRCVEv5kDuHVLMAbBg.mc1Ys0dAVLvzU82aRApQGVMoJ1z4vtrztMT77edvk+8NFWroACGNjc1YG52ueKKKfOWpeceigKilzHO6rytnFe0Z6ZEVtvpht+JBMGdtpCLMhV7niNBXQsGk1rWWbvoKmotOdBgnMEnM1XiVFGMes2TPac+pCZUjWvN6rSag1a5RXWAm1Drpo38RoDeLBRIt5.9ZojoSmhVppEMpXAlXqvxAVwv5U.tpT5ZPygJmy01wqtJ29EgFcY0Uvjau81KTP9kcb4.yKz7BhzqnGau81bu6cuVFmvE2aZRGra8qtr6lJDhOWvtUX4CqBX8JDWkMxzbP4niNZg.TcSIo6AzlsDX2.cMGJUJUqHRiBPptcoj8WVzU9GMedCqx985yN6rC6t6tKTSqtcYr49c2QZpAcYS0kc5JrbgUArdIwK5E9Rgj4ymyAGbvBoBBe95V0730kYPSmwZ5N3vgCQq0HEx14RrKVFYbs.qJVLPiVk7nceviTH4gu+CYyM2rk0oy4ZUBeCCpPHfpI3Dfplw0kCTsLdu5scrpFVujPTaLdosA+UjZXLxzymzdXpolJTmRWS63gZVWwXqNixz5VUbqTJ1e+8Y+c2idE8pOT1Q6Rc5fV2fe21OR94tmEWTA5BRKoCc8bQFBA1e28vnz7IexmjTBu1zJcgjeioZCNopGMJsR29Xz7ycUMrV9vJFVuhvyhok0Z4zSOkxxx1Nb0L3tcS4Atf4UVVVqNqZRIbu81i6e+6SQQwUxV3MUzsv5MAXxxxXznQb26d2EDSZ2zn8dORDKXOMMycIrHqtUX4AqXXcMiyN6LFOdL.sC5byGM5FponwNmCesZ1AZsbk81aO1c2cIOK+hUu9kXG7l5guqR1CBgfd85wN6rCFigCO7PN8zSIDBsCAcSfqFa64x0ypogE+zJf2U31AVEv5ZFEEErwFaPb7SwZsXpUqdyAHemYfq0BeqGDXsVyctycXmc1gh7BrNKJgrU46OK7llbG51fhti8jwX3N24Nr1Zqw74yYxjIb5om1JPzF1WMuwfVqaGsoU5vZ4DqVBEujn8l2y31nPH33iOlO9G9C.fY0l0WyLDl9VuPSQh5Add3vgrwFavnQiv68XLlzHkzodWW1ZZtpe1Ka3xub7ppKWy+9k+dhwHUUUK7QSJzMA3Ve80ugtRVgqCrJf0KIRCSb7YtYkaJX9ImcJe7G+wnLFN93ioe+9s0uRJkXLF50qGaMZDiFMhh7h1GiFWXnoo+WdDU.9bedy+1xFdQub7xWSMLnZt9aBh2cvxadyfKOugqvxGVEv5kDun.VsokHkTVUx29O+OGHkp3zoSas8jc1YmjiDzU.kHv4csKtBqyhQoaeL6p8H3pYmrrgqbXn6HDzm00zBcF8J96M3xZgaEVtvp.Vuj3EEvpEBAmO4bhBAO5QOBmyw68duGC2XX6JUWJknZ7Mq5QSoQuUM1cr.VfkvkOTtrqynmU.qlu1UkZXWVVWlw0UwxBVzELVgkG7+GPKlqa1f+rYM.....jTQNQjqBAlf" ],
					"embed" : 1,
					"forceaspect" : 1,
					"id" : "obj-14",
					"ignoreclick" : 1,
					"maxclass" : "fpic",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "jit_matrix" ],
					"patching_rect" : [ 136.5, 181.0, 567.34082, 590.034453 ],
					"pic" : "C:/Users/Andrew/Desktop/KinectSkeleton.jpg",
					"presentation" : 1,
					"presentation_rect" : [ 136.5, 181.0, 545.52002, 567.34082 ]
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-35", 10 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-1", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-12", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-10", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-35", 2 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-11", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-35", 9 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-13", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-35", 3 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-16", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-35", 13 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-18", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-8", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-2", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-35", 12 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-20", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-35", 7 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-22", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-35", 6 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-24", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-35", 4 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-26", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-35", 5 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-28", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-35", 1 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-3", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-30", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-11", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-30", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-13", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-30", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-16", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-30", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-18", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-30", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-20", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-30", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-22", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-30", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-24", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-30", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-26", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-30", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-28", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-30", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-3", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-30", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-4", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-30", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-5", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-30", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-7", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-30", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-9", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-30", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-30", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-31", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-35", 11 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-4", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-40", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-37", 1 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-40", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-39", 1 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-40", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-35", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-5", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-10", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-8", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-35", 8 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-9", 0 ]
				}

			}
 ],
		"dependency_cache" : [ 			{
				"name" : "KinectSkeleton.jpg",
				"bootpath" : "/Users/Andrew/Desktop",
				"patcherrelativepath" : "../../../../../Desktop",
				"type" : "JPEG",
				"implicit" : 1
			}
, 			{
				"name" : "Kinect Interface Joint Inlets.maxpat",
				"bootpath" : "~/Max 7/Projects/Kinect Max/patchers",
				"patcherrelativepath" : ".",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "Kinect Interface Joint Outlets.maxpat",
				"bootpath" : "~/Max 7/Projects/Kinect Max/patchers",
				"patcherrelativepath" : ".",
				"type" : "JSON",
				"implicit" : 1
			}
 ],
		"embedsnapshot" : 0
	}

}
