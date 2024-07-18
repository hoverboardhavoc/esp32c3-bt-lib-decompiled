/*
 * Last changed at upstream commit bfdfe8f851c99ced8316b133b0b15521917ea049
 * https://github.com/espressif/esp32c3-bt-lib/commit/bfdfe8f851c99ced8316b133b0b15521917ea049
 * Upstream date: 2024-07-18 14:51:28 +0800
 * Upstream subject: feat(bt): Support mesh duplicate with extend scan (aa16a46)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_frm_isr_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_frm_isr_eco(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = (**(code **)(_r_ip_funcs_p + 0x7dc))
                    ((int)(uint)*(ushort *)(*(int *)(&lld_con_env + param_1 * 4) + 0x84) >> 8 & 1,
                     *(code **)(_r_ip_funcs_p + 0x7dc));
  if (iVar1 != 0) {
    return;
  }
  iVar1 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if (*(char *)(iVar1 + 0x19) == '\x02') {
    (**(code **)(_r_ip_funcs_p + 0x9d8))(*(code **)(_r_ip_funcs_p + 0x9d8));
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

