/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
_L28:
      if (_g_bt_plf_log_level < 3) {
        return;
      }
      ets_printf("hi%d, lo%d\n",iVar3,iVar2);
      return;
    }
    if (iVar3 == 0) {
      iVar1 = iVar2;
      if (iVar2 == 0) {
_L40:
        iVar3 = iVar1;
        iVar2 = 1;
      }
      else if (iVar2 == 1) {
_L41:
        iVar2 = 2;
      }
      else if (iVar2 == 2) {
_L42:
        iVar2 = 3;
      }
      else if (iVar2 == 3) {
        iVar2 = 0;
        iVar3 = 1;
      }
    }
    else {
      iVar1 = iVar3;
      if (iVar3 == 1) {
        if (iVar2 == 0) goto _L40;
        if (iVar2 == 1) {
          iVar3 = 1;
          goto _L41;
        }
        if (iVar2 == 2) goto _L42;
        if (iVar2 == 3) {
          iVar2 = 0;
          iVar3 = 2;
        }
      }
      else if (iVar3 == 2) {
        if (iVar2 == 0) goto _L40;
        if (iVar2 == 1) goto _L41;
        if (iVar2 == 2) {
          iVar3 = 2;
          goto _L42;
        }
        if (iVar2 == 3) {
          iVar3 = 3;
          iVar2 = 0;
        }
      }
      else if (iVar3 == 3) {
        if (iVar2 == 0) goto _L40;
        if (iVar2 == 1) goto _L41;
        if (iVar2 == 2) goto _L42;
        if (iVar2 == 3) {
          iVar3 = iVar2;
          if (2 < _g_bt_plf_log_level) {
            ets_printf("phase match cali failed!\n",3);
          }
          goto _L28;
        }
      }
    }
    _DAT_600310f8 = _DAT_600310f8 & 0xfffff88e | iVar3 << 8 | iVar2 << 4 | 1;
    ets_delay_us(1);
  } while( true );
}

