/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> emi.o -> r_emi_em_base_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_emi_em_base_init(void)

{
  int iVar1;
  undefined4 uVar2;
  void *pvVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  int iVar8;
  uint *puVar9;
  uint uVar10;
  
  pvVar3 = (void *)(**(code **)(_r_osi_funcs_p + 0x78))(0x148,*(code **)(_r_osi_funcs_p + 0x78));
  if (pvVar3 != (void *)0x0) {
    memset(pvVar3,0,0x148);
    if (2 < _g_bt_plf_log_level) {
      ets_printf("EM ET %04x, %p, len %d\n",0,pvVar3,0x148);
    }
    _DAT_60031204 = (uint)((int)pvVar3 << 0xc) >> 0xe;
    _DAT_600312c4 = _DAT_600312c4 | 1;
    pvVar3 = (void *)(**(code **)(_r_osi_funcs_p + 0x78))(0x438,*(code **)(_r_osi_funcs_p + 0x78));
    if (pvVar3 != (void *)0x0) {
      memset(pvVar3,0,0x438);
      if (2 < _g_bt_plf_log_level) {
        ets_printf("EM CS %04x, %p, len %d\n",0x400,pvVar3,0x438);
      }
      _DAT_60031208 = (uint)((int)pvVar3 << 0xc) >> 0xe | 0x4000000;
      _DAT_600312c4 = _DAT_600312c4 | 2;
      pvVar3 = (void *)(**(code **)(_r_osi_funcs_p + 0x78))(0x268,*(code **)(_r_osi_funcs_p + 0x78))
      ;
      if (pvVar3 != (void *)0x0) {
        memset(pvVar3,0,0x268);
        if (2 < _g_bt_plf_log_level) {
          ets_printf("EM WL/RAL %04x, %p, len %d\n",0xc00,pvVar3,0x268);
        }
        _DAT_6003120c = (uint)((int)pvVar3 << 0xc) >> 0xe | 0xc000000;
        _DAT_600312c4 = _DAT_600312c4 | 4;
        pvVar3 = (void *)(**(code **)(_r_osi_funcs_p + 0x78))(200,*(code **)(_r_osi_funcs_p + 0x78))
        ;
        if (pvVar3 != (void *)0x0) {
          memset(pvVar3,0,200);
          if (2 < _g_bt_plf_log_level) {
            ets_printf("EM RXDESC %04x, %p, len %d\n",0x1000,pvVar3,200);
          }
          _DAT_60031210 = (uint)((int)pvVar3 << 0xc) >> 0xe | 0x10000000;
          _DAT_600312c4 = _DAT_600312c4 | 8;
          pvVar3 = (void *)(**(code **)(_r_osi_funcs_p + 0x78))
                                     (0x4ec,*(code **)(_r_osi_funcs_p + 0x78));
          if (pvVar3 != (void *)0x0) {
            memset(pvVar3,0,0x4ec);
            if (2 < _g_bt_plf_log_level) {
              ets_printf("EM TXDESC %04x, %p, len %d\n",0x1400,pvVar3,0x4ec);
            }
            _DAT_60031214 = (uint)((int)pvVar3 << 0xc) >> 0xe | 0x14000000;
            _DAT_600312c4 = _DAT_600312c4 | 0x10;
            pvVar3 = (void *)(**(code **)(_r_osi_funcs_p + 0x78))
                                       (0x21c,*(code **)(_r_osi_funcs_p + 0x78));
            if (pvVar3 != (void *)0x0) {
              memset(pvVar3,0,0x21c);
              if (2 < _g_bt_plf_log_level) {
                ets_printf("EM LLCP TX BUFFER %04x, %p, len %d\n",0x1c00,pvVar3,0x21c);
              }
              _DAT_60031218 = (uint)((int)pvVar3 << 0xc) >> 0xe | 0x1c000000;
              _DAT_600312c4 = _DAT_600312c4 | 0x20;
              pvVar3 = (void *)(**(code **)(_r_osi_funcs_p + 0x78))
                                         (0x2ee,*(code **)(_r_osi_funcs_p + 0x78));
              if (pvVar3 != (void *)0x0) {
                memset(pvVar3,0,0x2ee);
                if (2 < _g_bt_plf_log_level) {
                  ets_printf("EM ADV EXT HDR TX BUFFER %04x, %p, len %d\n",0x2000,pvVar3,0x2ee);
                }
                _DAT_6003121c = (uint)((int)pvVar3 << 0xc) >> 0xe | 0x20000000;
                _DAT_600312c4 = _DAT_600312c4 | 0x40;
                iVar1 = 0;
                do {
                  iVar8 = iVar1 * 0x800 + 0x2400;
                  if (2 < _g_bt_plf_log_level) {
                    ets_printf("EM ADV DATA TX BUFFER[%d] %04x, NULL, len %d\n",iVar1,iVar8,0x2ee);
                  }
                  *(int *)(&DAT_60031220 + iVar1 * 4) = iVar8 * 0x10000;
                  _DAT_600312c4 = ~(1 << (iVar1 + 7U & 0x1f)) & _DAT_600312c4;
                  iVar1 = iVar1 + 1;
                } while (iVar1 != 10);
                pvVar3 = (void *)(**(code **)(_r_osi_funcs_p + 0x78))
                                           (0x66,*(code **)(_r_osi_funcs_p + 0x78));
                if (pvVar3 != (void *)0x0) {
                  memset(pvVar3,0,0x66);
                  if (2 < _g_bt_plf_log_level) {
                    ets_printf("EM AUX CONNECT REQ TX BUFFER %04x, %p, len %d\n",0x7400,pvVar3,0x66)
                    ;
                  }
                  _DAT_60031248 = (uint)pvVar3 >> 2 & 0x3ffff | 0x74000000;
                  _DAT_600312c4 = _DAT_600312c4 & 0xfffdffff | 0x20000;
                  iVar1 = 0;
                  do {
                    pvVar3 = (void *)(**(code **)(_r_osi_funcs_p + 0x78))
                                               (0x110,*(code **)(_r_osi_funcs_p + 0x78));
                    if (pvVar3 == (void *)0x0) goto _L20;
                    memset(pvVar3,0,0x110);
                    iVar8 = iVar1 * 0x400 + 0x7800;
                    if (2 < _g_bt_plf_log_level) {
                      ets_printf("EM DATA RX BUFFER[%d] %04x, %p, len %d\n",iVar1,iVar8,pvVar3,0x110
                                );
                    }
                    *(uint *)(iVar1 * 4 + 0x6003124c) =
                         (uint)pvVar3 >> 2 & 0x3ffff | iVar8 * 0x10000;
                    uVar7 = 1 << (iVar1 + 0x12U & 0x1f);
                    _DAT_600312c4 = ~uVar7 & _DAT_600312c4 | uVar7;
                    iVar1 = iVar1 + 1;
                  } while (iVar1 != 9);
                  puVar9 = (uint *)&DAT_60031270;
                  uVar7 = 0x9c00;
                  uVar10 = 0x1b;
                  uVar2 = 0x110;
                  do {
                    iVar8 = uVar10 - 0x1b;
                    iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
                    if (iVar8 < (int)(uint)*(byte *)(iVar1 + 0x10)) {
                      pvVar3 = (void *)(**(code **)(_r_osi_funcs_p + 0x78))
                                                 (0x100,*(code **)(_r_osi_funcs_p + 0x78));
                      if (pvVar3 == (void *)0x0) break;
                      memset(pvVar3,0,0x100);
                      if (2 < _g_bt_plf_log_level) {
                        ets_printf("EM ACL TX STATIC BUFFER[%d] %04x, %p, len %d\n",iVar8,uVar7,
                                   pvVar3,0x100);
                      }
                      *puVar9 = (uint)pvVar3 >> 2 & 0x3ffff | (uVar7 >> 2) << 0x12;
                      if (uVar10 < 0x20) {
                        puVar6 = (uint *)&DAT_600312c4;
                        uVar4 = _DAT_600312c4;
                        uVar5 = uVar10;
                      }
                      else {
                        uVar5 = uVar10 - 0x20;
                        puVar6 = (uint *)&DAT_600312c8;
                        uVar4 = _DAT_600312c8;
                      }
                      uVar5 = 1 << (uVar5 & 0x1f);
                      *puVar6 = ~uVar5 & uVar4 | uVar5;
                      uVar2 = 0x100;
                    }
                    else {
                      if (2 < _g_bt_plf_log_level) {
                        ets_printf("EM ACL TX DYNAMIC BUFFER[%d] %04x, NULL, len %d\n",iVar8,uVar7,
                                   uVar2);
                      }
                      *puVar9 = (uVar7 >> 2) << 0x12;
                      if (uVar10 < 0x20) {
                        puVar6 = (uint *)&DAT_600312c4;
                        uVar4 = _DAT_600312c4;
                        uVar5 = uVar10;
                      }
                      else {
                        puVar6 = (uint *)&DAT_600312c8;
                        uVar5 = uVar10 - 0x20;
                        uVar4 = _DAT_600312c8;
                      }
                      *puVar6 = ~(1 << (uVar5 & 0x1f)) & uVar4;
                    }
                    uVar10 = uVar10 + 1;
                    uVar7 = uVar7 + 0x400;
                    puVar9 = puVar9 + 1;
                    if (uVar10 == 0x27) {
                      if (em_base_reg_lut != 0x26) {
                        (**(code **)(_r_plf_funcs_p + 0xc))
                                  (0x27,em_base_reg_lut + 1,0x10000,0xfd,
                                   *(code **)(_r_plf_funcs_p + 0xc));
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
_L20:
  (**(code **)(_r_plf_funcs_p + 0xa4))(*(code **)(_r_plf_funcs_p + 0xa4));
  return 7;
}

