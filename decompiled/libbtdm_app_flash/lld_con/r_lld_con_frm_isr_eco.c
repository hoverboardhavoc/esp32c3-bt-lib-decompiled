/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_frm_isr_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_con_frm_isr_eco(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = r_lld_con_terminate_max_evt_update
                    ((int)(uint)*(ushort *)(*(int *)(&lld_con_env + param_1 * 4) + 0x84) >> 8 & 1);
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

