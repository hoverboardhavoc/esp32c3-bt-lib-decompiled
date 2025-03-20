/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_frm_isr_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_con_frm_isr_eco(uint param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  iVar1 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar1 + 0x28) & 0x20) != 0) &&
     (iVar1 = r_sdk_config_get_opts_ext(), *(byte *)(iVar1 + 0x2c) < 3)) {
    r_ble_log_internal_x2(0x4043000a,param_3 << 8 | param_1,param_2);
  }
  iVar1 = r_lld_con_terminate_max_evt_update
                    (param_1,(int)(uint)*(ushort *)(*(int *)(&lld_con_env + param_1 * 4) + 0x84) >>
                             8 & 1);
  if (iVar1 != 0) {
    return;
  }
  iVar1 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar1 + 0x19) == '\x02') {
    r_lld_cca_con_evt_end_handle();
  }
  r_lld_con_frm_isr(param_1,param_2,param_3);
  if (con_evt_func_cb == (code *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00010016. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*con_evt_func_cb)(param_1,0);
  return;
}

