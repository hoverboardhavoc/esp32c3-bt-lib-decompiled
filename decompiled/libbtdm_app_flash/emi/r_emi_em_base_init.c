/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> emi.o -> r_emi_em_base_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_emi_em_base_init(void)

{
  void *pvVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  undefined4 uVar7;
  
  pvVar1 = (void *)(**(code **)(_r_osi_funcs_p + 0x78))(0x148,*(code **)(_r_osi_funcs_p + 0x78));
  if (pvVar1 != (void *)0x0) {
    memset(pvVar1,0,0x148);
    if (2 < _g_bt_plf_log_level) {
      ets_printf("EM ET %04x, %p, len %d\n",0,pvVar1,0x148);
    }
    _DAT_60031204 = (uint)((int)pvVar1 << 0xc) >> 0xe;
    _DAT_600312c4 = _DAT_600312c4 | 1;
    pvVar1 = (void *)(**(code **)(_r_osi_funcs_p + 0x78))(0x438,*(code **)(_r_osi_funcs_p + 0x78));
    if (pvVar1 != (void *)0x0) {
      memset(pvVar1,0,0x438);
      if (2 < _g_bt_plf_log_level) {
        ets_printf("EM CS %04x, %p, len %d\n",0x400,pvVar1,0x438);
      }
      _DAT_60031208 = (uint)((int)pvVar1 << 0xc) >> 0xe | 0x4000000;
      _DAT_600312c4 = _DAT_600312c4 | 2;
      pvVar1 = (void *)(**(code **)(_r_osi_funcs_p + 0x78))(0x268,*(code **)(_r_osi_funcs_p + 0x78))
      ;
      if (pvVar1 != (void *)0x0) {
        memset(pvVar1,0,0x268);
        if (2 < _g_bt_plf_log_level) {
          ets_printf("EM WL/RAL %04x, %p, len %d\n",0xc00,pvVar1,0x268);
        }
        _DAT_6003120c = (uint)((int)pvVar1 << 0xc) >> 0xe | 0xc000000;
        _DAT_600312c4 = _DAT_600312c4 | 4;
        pvVar1 = (void *)(**(code **)(_r_osi_funcs_p + 0x78))(200,*(code **)(_r_osi_funcs_p + 0x78))
        ;
        if (pvVar1 != (void *)0x0) {
          memset(pvVar1,0,200);
          if (2 < _g_bt_plf_log_level) {
            ets_printf("EM RXDESC %04x, %p, len %d\n",0x1000,pvVar1,200);
          }
          _DAT_60031210 = (uint)((int)pvVar1 << 0xc) >> 0xe | 0x10000000;
          _DAT_600312c4 = _DAT_600312c4 | 8;
          pvVar1 = (void *)(**(code **)(_r_osi_funcs_p + 0x78))
                                     (0x4ec,*(code **)(_r_osi_funcs_p + 0x78));
          if (pvVar1 != (void *)0x0) {
            memset(pvVar1,0,0x4ec);
            if (2 < _g_bt_plf_log_level) {
              ets_printf("EM TXDESC %04x, %p, len %d\n",0x1400,pvVar1,0x4ec);
            }
            _DAT_60031214 = (uint)((int)pvVar1 << 0xc) >> 0xe | 0x14000000;
            _DAT_600312c4 = _DAT_600312c4 | 0x10;
            pvVar1 = (void *)(**(code **)(_r_osi_funcs_p + 0x78))
                                       (0x21c,*(code **)(_r_osi_funcs_p + 0x78));
            if (pvVar1 != (void *)0x0) {
              memset(pvVar1,0,0x21c);
              if (2 < _g_bt_plf_log_level) {
                ets_printf("EM LLCP TX BUFFER %04x, %p, len %d\n",0x1c00,pvVar1,0x21c);
              }
              _DAT_60031218 = (uint)((int)pvVar1 << 0xc) >> 0xe | 0x1c000000;
              _DAT_600312c4 = _DAT_600312c4 | 0x20;
              pvVar1 = (void *)(**(code **)(_r_osi_funcs_p + 0x78))
                                         (0x2ee,*(code **)(_r_osi_funcs_p + 0x78));
              if (pvVar1 != (void *)0x0) {
                memset(pvVar1,0,0x2ee);
                if (2 < _g_bt_plf_log_level) {
                  ets_printf("EM ADV EXT HDR TX BUFFER %04x, %p, len %d\n",0x2000,pvVar1,0x2ee);
                }
                _DAT_6003121c = (uint)((int)pvVar1 << 0xc) >> 0xe | 0x20000000;
                _DAT_600312c4 = _DAT_600312c4 | 0x40;
                iVar4 = 0;
                do {
                  if (2 < _g_bt_plf_log_level) {
                    ets_printf("EM ADV DATA TX BUFFER[%d] %04x, NULL, len %d\n",iVar4,
                               iVar4 * 0x800 + 0x2400,0x2ee);
                  }
                  *(uint *)(&DAT_60031220 + iVar4 * 4) =
                       (((uint)(iVar4 * 0x800) >> 2) + 0x900) * 0x40000;
                  _DAT_600312c4 = ~(1 << (iVar4 + 7U & 0x1f)) & _DAT_600312c4;
                  iVar4 = iVar4 + 1;
                } while (iVar4 != 10);
                pvVar1 = (void *)(**(code **)(_r_osi_funcs_p + 0x78))
                                           (0x66,*(code **)(_r_osi_funcs_p + 0x78));
                if (pvVar1 != (void *)0x0) {
                  memset(pvVar1,0,0x66);
                  if (2 < _g_bt_plf_log_level) {
                    ets_printf("EM AUX CONNECT REQ TX BUFFER %04x, %p, len %d\n",0x7400,pvVar1,0x66)
                    ;
                  }
                  _DAT_60031248 = (uint)pvVar1 >> 2 & 0x3ffff | 0x74000000;
                  _DAT_600312c4 = _DAT_600312c4 | 0x20000;
                  iVar4 = 0;
                  do {
                    pvVar1 = (void *)(**(code **)(_r_osi_funcs_p + 0x78))
                                               (0x110,*(code **)(_r_osi_funcs_p + 0x78));
                    if (pvVar1 == (void *)0x0) goto _L19;
                    memset(pvVar1,0,0x110);
                    if (2 < _g_bt_plf_log_level) {
                      ets_printf("EM DATA RX BUFFER[%d] %04x, %p, len %d\n",iVar4,
                                 iVar4 * 0x400 + 0x7800,pvVar1,0x110);
                    }
                    *(uint *)(iVar4 * 4 + 0x6003124c) =
                         (((uint)(iVar4 * 0x400) >> 2) + 0x1e00) * 0x40000 |
                         (uint)pvVar1 >> 2 & 0x3ffff;
                    uVar3 = 1 << (iVar4 + 0x12U & 0x1f);
                    _DAT_600312c4 = ~uVar3 & _DAT_600312c4 | uVar3;
                    iVar4 = iVar4 + 1;
                  } while (iVar4 != 9);
                  puVar5 = (uint *)&DAT_60031270;
                  uVar3 = 0;
                  uVar6 = 0x1b;
                  uVar7 = 0x110;
                  do {
                    iVar4 = r_sdk_config_get_opts();
                    if ((int)(uVar6 - 0x1b) < (int)(uint)*(byte *)(iVar4 + 0x10)) {
                      pvVar1 = (void *)(**(code **)(_r_osi_funcs_p + 0x78))
                                                 (0x100,*(code **)(_r_osi_funcs_p + 0x78));
                      if (pvVar1 == (void *)0x0) break;
                      memset(pvVar1,0,0x100);
                      if (2 < _g_bt_plf_log_level) {
                        ets_printf("EM ACL TX STATIC BUFFER[%d] %04x, %p, len %d\n",uVar6 - 0x1b,
                                   uVar3 + 0x9c00,pvVar1,0x100);
                      }
                      *puVar5 = ((uVar3 >> 2) + 0x2700) * 0x40000 | (uint)pvVar1 >> 2 & 0x3ffff;
                      if (uVar6 < 0x20) {
                        uVar2 = 1 << (uVar6 & 0x1f);
                        _DAT_600312c4 = ~uVar2 & _DAT_600312c4 | uVar2;
                      }
                      else {
                        uVar2 = 1 << (uVar6 - 0x20 & 0x1f);
                        _DAT_600312c8 = ~uVar2 & _DAT_600312c8 | uVar2;
                      }
                      uVar7 = 0x100;
                    }
                    else {
                      if (2 < _g_bt_plf_log_level) {
                        ets_printf("EM ACL TX DYNAMIC BUFFER[%d] %04x, NULL, len %d\n",uVar6 - 0x1b,
                                   uVar3 + 0x9c00,uVar7);
                      }
                      *puVar5 = ((uVar3 >> 2) + 0x2700) * 0x40000;
                      if (uVar6 < 0x20) {
                        _DAT_600312c4 = ~(1 << (uVar6 & 0x1f)) & _DAT_600312c4;
                      }
                      else {
                        _DAT_600312c8 = ~(1 << (uVar6 - 0x20 & 0x1f)) & _DAT_600312c8;
                      }
                    }
                    uVar3 = uVar3 + 0x400;
                    uVar6 = uVar6 + 1;
                    puVar5 = puVar5 + 1;
                    if (uVar3 == 0x3000) {
                      if (em_base_reg_lut != 0x26) {
                        r_assert_param(0x27,em_base_reg_lut + 1,0x10000,0xfd);
                      }
                      if (2 < _g_bt_plf_log_level) {
                        ets_printf("FINAL EM IDX %d,\n",0x27);
                      }
                      _DAT_600312a0 = 0xcc000000;
                      _DAT_600312c8 = _DAT_600312c8 & 0xffffff7f;
                      return 0;
                    }
                  } while( true );
                }
              }
            }
          }
        }
      }
    }
  }
_L19:
  r_emi_em_base_deinit();
  return 7;
}

