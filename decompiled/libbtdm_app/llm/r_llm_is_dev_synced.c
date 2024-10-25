/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llm.o -> r_llm_is_dev_synced
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool r_llm_is_dev_synced(undefined4 param_1,byte param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  
  for (uVar1 = 0; iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38)),
      uVar1 < *(byte *)(iVar2 + 0xd); uVar1 = uVar1 + 1 & 0xff) {
    iVar2 = *(int *)(_p_llm_env + 8) + uVar1 * 0x44;
    if ((((*(char *)(iVar2 + 0x40) == '\x0f') &&
         (iVar2 = (*(code *)*_r_modules_funcs_p)(param_1,iVar2 + 4,(code *)*_r_modules_funcs_p),
         iVar2 != 0)) &&
        (iVar2 = *(int *)(_p_llm_env + 8) + uVar1 * 0x44,
        ((param_2 ^ *(byte *)(iVar2 + 0x41)) & 1) == 0)) && (*(byte *)(iVar2 + 0x28) == param_3))
    break;
  }
  iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  return uVar1 < *(byte *)(iVar2 + 0xd);
}

