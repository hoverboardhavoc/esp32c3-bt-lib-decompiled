/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> vhci.o -> r_vhci_send_to_host
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_vhci_send_to_host(int param_1,uint param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  
  if (param_1 == 0) {
    if (0 < _g_bt_plf_log_level) {
      ets_printf("%s %d\n",0x10000,0xf2);
    }
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if (param_2 == 0) {
    if (0 < _g_bt_plf_log_level) {
      ets_printf("%s %d\n",0x10000,0xf3);
    }
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if ((*(int *)(_vhci_env_p + 8) != 0) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(_vhci_env_p + 8) + 4),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0001039e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(param_2 & 0xffff);
    return;
  }
  return;
}

