/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> emi.o -> r_emi_em_base_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_emi_em_base_init(void)

{
  int iVar1;
  void *pvVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  
  pvVar2 = (void *)(**(code **)(_r_osi_funcs_p + 0x78))(0x148,*(code **)(_r_osi_funcs_p + 0x78));
  if (pvVar2 != (void *)0x0) {
    memset(pvVar2,0,0x148);
    if (2 < _g_bt_plf_log_level) {
      ets_printf("EM ET %04x, %p, len %d\n",0,pvVar2,0x148);
    }
    _DAT_60031204 = (uint)((int)pvVar2 << 0xc) >> 0xe;
    _DAT_600312c4 = _DAT_600312c4 | 1;
    pvVar2 = (void *)(**(code **)(_r_osi_funcs_p + 0x78))(0x438,*(code **)(_r_osi_funcs_p + 0x78));
    if (pvVar2 != (void *)0x0) {
      memset(pvVar2,0,0x438);
      if (2 < _g_bt_plf_log_level) {
        ets_printf("EM CS %04x, %p, len %d\n",0x400,pvVar2,0x438);
      }
      _DAT_60031208 = (uint)((int)pvVar2 << 0xc) >> 0xe | 0x4000000;
      _DAT_600312c4 = _DAT_600312c4 | 2;
      pvVar2 = (void *)(**(code **)(_r_osi_funcs_p + 0x78))(0x268,*(code **)(_r_osi_funcs_p + 0x78))
      ;
      if (pvVar2 != (void *)0x0) {
        memset(pvVar2,0,0x268);
        if (2 < _g_bt_plf_log_level) {
          ets_printf("EM WL/RAL %04x, %p, len %d\n",0xc00,pvVar2,0x268);
        }
        _DAT_6003120c = (uint)((int)pvVar2 << 0xc) >> 0xe | 0xc000000;
        _DAT_600312c4 = _DAT_600312c4 | 4;
        pvVar2 = (void *)(**(code **)(_r_osi_funcs_p + 0x78))(200,*(code **)(_r_osi_funcs_p + 0x78))
        ;
        if (pvVar2 != (void *)0x0) {
          memset(pvVar2,0,200);
          if (2 < _g_bt_plf_log_level) {
            ets_printf("EM RXDESC %04x, %p, len %d\n",0x1000,pvVar2,200);
          }
          _DAT_60031210 = (uint)((int)pvVar2 << 0xc) >> 0xe | 0x10000000;
          _DAT_600312c4 = _DAT_600312c4 | 8;
          pvVar2 = (void *)(**(code **)(_r_osi_funcs_p + 0x78))
                                     (0x4ec,*(code **)(_r_osi_funcs_p + 0x78));
          if (pvVar2 != (void *)0x0) {
            memset(pvVar2,0,0x4ec);
            if (2 < _g_bt_plf_log_level) {
              ets_printf("EM TXDESC %04x, %p, len %d\n",0x1400,pvVar2,0x4ec);
            }
            _DAT_60031214 = (uint)((int)pvVar2 << 0xc) >> 0xe | 0x14000000;
            _DAT_600312c4 = _DAT_600312c4 | 0x10;
            pvVar2 = (void *)(**(code **)(_r_osi_funcs_p + 0x78))
                                       (0x21c,*(code **)(_r_osi_funcs_p + 0x78));
            if (pvVar2 != (void *)0x0) {
              memset(pvVar2,0,0x21c);
              if (2 < _g_bt_plf_log_level) {
                ets_printf("EM LLCP TX BUFFER %04x, %p, len %d\n",0x1c00,pvVar2,0x21c);
              }
              _DAT_60031218 = (uint)((int)pvVar2 << 0xc) >> 0xe | 0x1c000000;
              _DAT_600312c4 = _DAT_600312c4 | 0x20;
              pvVar2 = (void *)(**(code **)(_r_osi_funcs_p + 0x78))
                                         (0x2ee,*(code **)(_r_osi_funcs_p + 0x78));
              if (pvVar2 != (void *)0x0) {
                memset(pvVar2,0,0x2ee);
                if (2 < _g_bt_plf_log_level) {
                  ets_printf("EM ADV EXT HDR TX BUFFER %04x, %p, len %d\n",0x2000,pvVar2,0x2ee);
                }
                _DAT_6003121c = (uint)((int)pvVar2 << 0xc) >> 0xe | 0x20000000;
                _DAT_600312c4 = _DAT_600312c4 | 0x40;
                iVar1 = 0;
                do {
                  iVar4 = iVar1 * 0x800 + 0x2400;
                  if (2 < _g_bt_plf_log_level) {
                    ets_printf("EM ADV DATA TX BUFFER[%d] %04x, NULL, len %d\n",iVar1,iVar4,0x2ee);
                  }
                  *(int *)(iVar1 * 4 + 0x60031220) = iVar4 * 0x10000;
                  _DAT_600312c4 = ~(1 << (iVar1 + 7U & 0x1f)) & _DAT_600312c4;
                  iVar1 = iVar1 + 1;
                } while (iVar1 != 10);
                pvVar2 = (void *)(**(code **)(_r_osi_funcs_p + 0x78))
                                           (0x66,*(code **)(_r_osi_funcs_p + 0x78));
                if (pvVar2 != (void *)0x0) {
                  memset(pvVar2,0,0x66);
                  if (2 < _g_bt_plf_log_level) {
                    ets_printf("EM AUX CONNECT REQ TX BUFFER %04x, %p, len %d\n",0x7400,pvVar2,0x66)
                    ;
                  }
                  _DAT_60031248 = (uint)pvVar2 >> 2 & 0x3ffff | 0x74000000;
                  _DAT_600312c4 = _DAT_600312c4 & 0xfffdffff | 0x20000;
                  iVar1 = 0;
                  do {
                    pvVar2 = (void *)(**(code **)(_r_osi_funcs_p + 0x78))
                                               (0x110,*(code **)(_r_osi_funcs_p + 0x78));
                    if (pvVar2 == (void *)0x0) goto _L18;
                    memset(pvVar2,0,0x110);
                    iVar4 = iVar1 * 0x400 + 0x7800;
                    if (2 < _g_bt_plf_log_level) {
                      ets_printf("EM DATA RX BUFFER[%d] %04x, %p, len %d\n",iVar1,iVar4,pvVar2,0x110
                                );
                    }
                    *(uint *)(iVar1 * 4 + 0x6003124c) =
                         (uint)pvVar2 >> 2 & 0x3ffff | iVar4 * 0x10000;
                    uVar3 = 1 << (iVar1 + 0x12U & 0x1f);
                    _DAT_600312c4 = ~uVar3 & _DAT_600312c4 | uVar3;
                    iVar1 = iVar1 + 1;
                  } while (iVar1 != 9);
                  iVar1 = 0;
                  uVar5 = 0x110;
                  do {
                    iVar4 = r_sdk_config_get_opts();
                    if (iVar1 < (int)(uint)*(byte *)(iVar4 + 0x10)) {
                      pvVar2 = (void *)(**(code **)(_r_osi_funcs_p + 0x78))
                                                 (0x100,*(code **)(_r_osi_funcs_p + 0x78));
                      if (pvVar2 == (void *)0x0) break;
                      memset(pvVar2,0,0x100);
                      iVar4 = iVar1 * 0x400 + 0x9c00;
                      if (2 < _g_bt_plf_log_level) {
                        ets_printf("EM ACL TX STATIC BUFFER[%d] %04x, %p, len %d\n",iVar1,iVar4,
                                   pvVar2,0x100);
                      }
                      *(uint *)(iVar1 * 4 + 0x60031270) =
                           (uint)pvVar2 >> 2 & 0x3ffff | iVar4 * 0x10000;
                      if (iVar1 + 0x1bU < 0x20) {
                        uVar3 = 1 << (iVar1 + 0x1bU & 0x1f);
                        _DAT_600312c4 = ~uVar3 & _DAT_600312c4 | uVar3;
                      }
                      else {
                        uVar3 = 1 << (iVar1 - 5U & 0x1f);
                        _DAT_600312c8 = ~uVar3 & _DAT_600312c8 | uVar3;
                      }
                      uVar5 = 0x100;
                    }
                    else {
                      iVar4 = iVar1 * 0x400 + 0x9c00;
                      if (2 < _g_bt_plf_log_level) {
                        ets_printf("EM ACL TX DYNAMIC BUFFER[%d] %04x, NULL, len %d\n",iVar1,iVar4,
                                   uVar5);
                      }
                      *(int *)(iVar1 * 4 + 0x60031270) = iVar4 * 0x10000;
                      if (iVar1 + 0x1bU < 0x20) {
                        _DAT_600312c4 = ~(1 << (iVar1 + 0x1bU & 0x1f)) & _DAT_600312c4;
                      }
                      else {
                        _DAT_600312c8 = ~(1 << (iVar1 - 5U & 0x1f)) & _DAT_600312c8;
                      }
                    }
                    iVar1 = iVar1 + 1;
                    if (iVar1 == 0xc) {
                      if (em_base_reg_lut != 0x26) {
                        r_assert_param(0x27,em_base_reg_lut + 1,"emi.c",0xff);
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
_L18:
  r_emi_em_base_deinit();
  return 7;
}

