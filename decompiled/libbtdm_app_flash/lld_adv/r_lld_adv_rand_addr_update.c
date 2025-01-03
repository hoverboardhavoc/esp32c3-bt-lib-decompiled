/*
 * Last changed at upstream commit ed99228396aaa18935b575d600bc19da38dc4746
 * https://github.com/espressif/esp32c3-bt-lib/commit/ed99228396aaa18935b575d600bc19da38dc4746
 * Upstream date: 2025-01-03 16:50:09 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(fd62b31)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_rand_addr_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_rand_addr_update(int param_1,undefined4 param_2,undefined2 param_3)

{
  int iVar1;
  undefined2 uStack_18;
  undefined2 uStack_16;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  if (*(int *)(&lld_adv_env + param_1 * 4) == 0) {
    r_assert_err(0,"lld_adv.c",0xddf);
  }
  else if ((*(byte *)(*(int *)(&lld_adv_env + param_1 * 4) + 0x8b) & 1) != 0) {
    uStack_18 = (undefined2)param_2;
    iVar1 = r_emi_get_mem_addr_by_offset(0x400);
    param_1 = param_1 * 0x5a;
    *(undefined2 *)(iVar1 + param_1 + 6) = uStack_18;
    uStack_16 = (undefined2)((uint)param_2 >> 0x10);
    iVar1 = r_emi_get_mem_addr_by_offset(0x400);
    *(undefined2 *)(iVar1 + param_1 + 8) = uStack_16;
    iVar1 = r_emi_get_mem_addr_by_offset(0x400);
    *(undefined2 *)(param_1 + 10 + iVar1) = param_3;
  }
                    /* WARNING: Could not recover jumptable at 0x00015cb8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x18))();
  return;
}

