/*
 * Last changed at upstream commit ed99228396aaa18935b575d600bc19da38dc4746
 * https://github.com/espressif/esp32c3-bt-lib/commit/ed99228396aaa18935b575d600bc19da38dc4746
 * Upstream date: 2025-01-03 16:50:09 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(fd62b31)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_adv_scan_rsp_data_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_scan_rsp_data_update(int param_1,undefined2 param_2,undefined2 param_3)

{
  int iVar1;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar1 = *(int *)(&lld_adv_env + param_1 * 4);
  if (iVar1 == 0) {
    ets_printf("adv_rsp_free\n");
  }
  else if (*(char *)(iVar1 + 0x89) == '\0') {
    (**(code **)(_r_ip_funcs_p + 0x1d8))(1,0,*(code **)(_r_ip_funcs_p + 0x1d8));
  }
  else {
    if (*(short *)(iVar1 + 0x26) != 0) {
      (**(code **)(_r_ip_funcs_p + 0xd8))(*(code **)(_r_ip_funcs_p + 0xd8));
    }
    iVar1 = *(int *)(&lld_adv_env + param_1 * 4);
    *(undefined2 *)(iVar1 + 0x2a) = param_2;
    *(undefined2 *)(iVar1 + 0x26) = param_3;
  }
                    /* WARNING: Could not recover jumptable at 0x00016216. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x18))();
  return;
}

