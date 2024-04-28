/*
 * Last changed at upstream commit 4b1338827fa19fbacc02dd9e46e76be2b0dd17a9
 * https://github.com/espressif/esp32c3-bt-lib/commit/4b1338827fa19fbacc02dd9e46e76be2b0dd17a9
 * Upstream date: 2024-04-28 11:58:26 +0800
 * Upstream subject: fix(coex): Fixed some coexist issues(ba3b3e3)
 * Source: libbtdm_app -> coex_schm.o -> coex_schm_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void coex_schm_process(void)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = (**(code **)(_r_osi_funcs_p + 0xe8))(*(code **)(_r_osi_funcs_p + 0xe8));
  if (iVar6 != 0) {
    coex_schm_btdm_env._0_1_ = 1;
                    /* WARNING: Could not recover jumptable at 0x00010138. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_osi_funcs_p + 0xec))();
    return;
  }
  DAT_000101d3 = 0;
  iVar6 = (**(code **)(_r_osi_funcs_p + 200))(*(code **)(_r_osi_funcs_p + 200));
  if (iVar6 != 0) {
    iVar2 = (**(code **)(_r_modules_funcs_p + 0x2c4))(*(code **)(_r_modules_funcs_p + 0x2c4));
    pbVar3 = (byte *)(**(code **)(_r_osi_funcs_p + 200))(*(code **)(_r_osi_funcs_p + 200));
    bVar1 = *pbVar3;
    iVar4 = (**(code **)(_r_osi_funcs_p + 0xc4))(*(code **)(_r_osi_funcs_p + 0xc4));
    iVar5 = (**(code **)(_r_osi_funcs_p + 0xc0))(*(code **)(_r_osi_funcs_p + 0xc0));
    DAT_000101d4 = ((iVar4 * iVar5 * (uint)bVar1) / 0x271) * 2 + iVar2 & 0xfffffff;
    if (3 < _g_bt_plf_log_level) {
      ets_printf("SCHM PROC %02x %02x, %p\n",*(undefined1 *)(iVar6 + 3),*(undefined1 *)(iVar6 + 2),
                 iVar6);
    }
    if ((*(byte *)(iVar6 + 2) & 0x20) != 0) {
      coex_schm_ble_scan_stop();
      return;
    }
  }
  return;
}

