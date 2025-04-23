/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> bt_rw_v9.o -> r_cali_phase_match_p
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_cali_phase_match_p(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (2 < _g_bt_plf_log_level) {
    ets_printf("phase match cali!!\n");
  }
  _DAT_600310f8 = _DAT_600310f8 & 0xfffff88e | 1;
  ets_delay_us(1);
  iVar2 = 0;
  iVar3 = 0;
  do {
    if ((_DAT_600310f8 & 0x1000) != 0) {
_L29:
      if (_g_bt_plf_log_level < 3) {
        return;
      }
      ets_printf("hi%d, lo%d\n",iVar2);
      return;
    }
    iVar1 = 0;
    if (iVar2 == 0) {
      if (iVar3 == 3) {
        iVar2 = 1;
      }
      else {
_L36:
        iVar1 = iVar3 + 1;
      }
    }
    else if (iVar2 == 1) {
      if (iVar3 != 3) goto _L36;
      iVar2 = 2;
    }
    else if (iVar2 == 2) {
      if (iVar3 != 3) goto _L36;
      iVar2 = 3;
    }
    else {
      if (iVar3 == 3) {
        if (_g_bt_plf_log_level < 3) {
          return;
        }
        ets_printf("phase match cali failed!\n");
        iVar2 = 3;
        goto _L29;
      }
      iVar1 = iVar3 + 1;
      iVar2 = 3;
    }
    _DAT_600310f8 = _DAT_600310f8 & 0xfffff88e | iVar2 << 8 | iVar1 << 4 | 1;
    ets_delay_us(1);
    iVar3 = iVar1;
  } while( true );
}

