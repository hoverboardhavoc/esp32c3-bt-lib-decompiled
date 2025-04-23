/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> hci_tl.o -> r_hci_ble_adv_report_filter_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_hci_ble_adv_report_filter_check(int param_1)

{
  byte bVar1;
  char cVar2;
  bool bVar3;
  
  if (*(short *)(param_1 + 4) != 0x1104) {
    return 0;
  }
  cVar2 = *(char *)(param_1 + 0xc);
  if (cVar2 == '\r') {
    cVar2 = DAT_00012022;
    if (*(char *)(param_1 + 0x17) == '\x01') {
      cVar2 = DAT_00012021;
    }
    bVar3 = true;
    if ((cVar2 != '\x02') && (bVar3 = false, cVar2 == '\0')) {
      bVar3 = 3 < g_bt_plf_log_level;
    }
    cVar2 = '\0';
    if ((*(ushort *)(param_1 + 0xe) & 0x60) == 0x20) {
      cVar2 = bVar3 + '\x01';
    }
    if (*(char *)(param_1 + 0x17) == '\x01') {
      DAT_00012021 = cVar2;
      cVar2 = DAT_00012022;
    }
    DAT_00012022 = cVar2;
    if (bVar3 == false) goto _L29;
    goto _L24;
  }
  if (cVar2 != '\x0f') {
    if (cVar2 != '\x02') {
      return 0;
    }
    if (3 < hci_tl_env) goto _L24;
    goto _L29;
  }
  bVar1 = *(byte *)(param_1 + 0xe);
  cVar2 = *(char *)(param_1 + 0x13);
  if ((&DAT_00012023)[bVar1] != '\x02') {
    if ((&DAT_00012023)[bVar1] == '\0') {
      if (cVar2 != '\x01') {
        if (3 < g_bt_plf_log_level) goto _L24;
        goto _L29;
      }
      if (3 < g_bt_plf_log_level) goto _L28;
    }
    else if (cVar2 != '\x01') {
      (&DAT_00012023)[bVar1] = 0;
      goto _L29;
    }
    (&DAT_00012023)[bVar1] = 1;
_L29:
    g_bt_plf_log_level = g_bt_plf_log_level + 1;
    return 0;
  }
  if (cVar2 != '\x01') {
    (&DAT_00012023)[bVar1] = 0;
    goto _L24;
  }
_L28:
  (&DAT_00012023)[bVar1] = 2;
_L24:
  (**(code **)(_r_modules_funcs_p + 0xd8))(*(code **)(_r_modules_funcs_p + 0xd8));
  return 1;
}

