/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
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
      ets_printf("%s %d\n",0x10000,0xfa);
    }
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if (param_2 == 0) {
    if (0 < _g_bt_plf_log_level) {
      ets_printf("%s %d\n",0x10000,0xfb);
    }
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if ((*(int *)(_vhci_env_p + 8) != 0) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(_vhci_env_p + 8) + 4),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00010422. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(param_2 & 0xffff);
    return;
  }
  return;
}

