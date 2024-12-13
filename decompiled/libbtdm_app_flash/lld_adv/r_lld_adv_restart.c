/*
 * Last changed at upstream commit c57c0b11c3c0065a16b66685715100a189ef9b27
 * https://github.com/espressif/esp32c3-bt-lib/commit/c57c0b11c3c0065a16b66685715100a189ef9b27
 * Upstream date: 2024-12-13 13:39:25 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(555b0a2)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_restart
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_restart(int param_1,int param_2,undefined2 param_3)

{
  uint uVar1;
  int iVar2;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar2 = *(int *)(&lld_adv_env + param_1 * 4);
  if (iVar2 == 0) {
    r_assert_err(0,"lld_adv.c",0xe01);
  }
  else {
    *(undefined1 *)(iVar2 + 0x86) = 0;
    *(undefined2 *)(iVar2 + 0x78) = param_3;
    if ((*(ushort *)(iVar2 + 0x74) & 8) == 0) {
      if (param_2 != 0) {
        *(uint *)(iVar2 + 0x58) = param_2 * 0x20 + *(int *)(iVar2 + 4) & 0xfffffff;
        goto _L1216;
      }
      uVar1 = 0xffffffff;
    }
    else {
      uVar1 = *(int *)(iVar2 + 4) + 0x1000U & 0xfffffff;
    }
    *(uint *)(iVar2 + 0x58) = uVar1;
  }
_L1216:
                    /* WARNING: Could not recover jumptable at 0x00015d28. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x18))();
  return;
}

