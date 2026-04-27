/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app -> llm_adv.o -> r_llm_adv_set_dft_params
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llm_adv_set_dft_params(int param_1)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  iVar3 = param_1 * 0x44;
  if (*(int *)(*(int *)(_p_llm_env + 8) + iVar3) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"llm_adv.c",0xcdf,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar5 = *(int *)(_p_llm_env + 8);
  uVar4 = (**(code **)(_r_modules_funcs_p + 200))(0,0,0,0x1a,*(code **)(_r_modules_funcs_p + 200));
  iVar1 = _p_llm_env;
  *(undefined4 *)(iVar5 + iVar3) = uVar4;
  puVar2 = *(undefined1 **)(*(int *)(iVar1 + 8) + iVar3);
  *puVar2 = 0xff;
  *(undefined2 *)(puVar2 + 2) = 0x13;
  *(undefined2 *)(puVar2 + 8) = 8;
  *(undefined2 *)(puVar2 + 4) = 0x800;
  *(undefined2 *)(puVar2 + 6) = 0;
  *(undefined2 *)(puVar2 + 10) = 7;
  puVar2[0xc] = 0;
  memset(puVar2 + 0xd,0,6);
  *(undefined2 *)(puVar2 + 0x14) = 0x17f;
  puVar2[0x13] = 0;
  *(undefined2 *)(puVar2 + 0x16) = 0x100;
  *(undefined2 *)(puVar2 + 0x18) = 0;
  iVar3 = *(int *)(iVar1 + 8) + iVar3;
  *(undefined4 *)(iVar3 + 4) = *(undefined4 *)(iVar1 + 0xc);
  *(undefined2 *)(iVar3 + 8) = *(undefined2 *)(iVar1 + 0x10);
  *(undefined1 *)(iVar3 + 0x40) = 1;
  if ((_bt_rf_coex_hooks_p != 0) && (*(code **)(_bt_rf_coex_hooks_p + 4) != (code *)0x0)) {
    uStack_24 = 0;
    uStack_2c = 0x800;
    uStack_28 = 7;
    (**(code **)(_bt_rf_coex_hooks_p + 4))(param_1,0,&uStack_2c);
  }
  return;
}

