/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
  
  if (2 < _g_bt_plf_log_level) {
    ets_printf("phase match cali!!\n");
  }
  _DAT_600310f8 = _DAT_600310f8 & 0xfffff88e | 1;
  ets_delay_us(1);
  iVar1 = 0;
  iVar2 = 0;
  do {
    if ((_DAT_600310f8 & 0x1000) != 0) {
_L27:
      if (2 < _g_bt_plf_log_level) {
        ets_printf("hi%d, lo%d\n",iVar2,iVar1);
        return;
      }
      return;
    }
    if (iVar2 == 0) {
      if (iVar1 == 0) {
_L39:
        iVar1 = 1;
      }
      else if (iVar1 == 1) {
_L40:
        iVar1 = 2;
      }
      else if (iVar1 == 2) {
_L41:
        iVar1 = 3;
      }
      else if (iVar1 == 3) {
        iVar1 = 0;
        iVar2 = 1;
      }
    }
    else if (iVar2 == 1) {
      if (iVar1 == 0) goto _L39;
      if (iVar1 == 1) goto _L40;
      if (iVar1 == 2) goto _L41;
      if (iVar1 == 3) {
        iVar1 = 0;
        iVar2 = 2;
      }
    }
    else if (iVar2 == 2) {
      if (iVar1 == 0) goto _L39;
      if (iVar1 == 1) goto _L40;
      if (iVar1 == 2) goto _L41;
      if (iVar1 == 3) {
        iVar2 = 3;
        iVar1 = 0;
      }
    }
    else if (iVar2 == 3) {
      if (iVar1 == 0) goto _L39;
      if (iVar1 == 1) goto _L40;
      if (iVar1 == 2) goto _L41;
      if (iVar1 == 3) {
        if (2 < _g_bt_plf_log_level) {
          ets_printf("phase match cali failed!\n");
          iVar2 = 3;
        }
        goto _L27;
      }
    }
    _DAT_600310f8 = _DAT_600310f8 & 0xfffff88e | iVar2 << 8 | iVar1 << 4 | 1;
    ets_delay_us(1);
  } while( true );
}

