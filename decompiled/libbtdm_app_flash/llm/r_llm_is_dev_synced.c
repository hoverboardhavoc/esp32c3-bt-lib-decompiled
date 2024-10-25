/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llm.o -> r_llm_is_dev_synced
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
  
  uVar1 = 0;
  while( true ) {
    iVar2 = r_sdk_config_get_opts();
    if (*(byte *)(iVar2 + 0xd) <= uVar1) break;
    iVar2 = *(int *)(_p_llm_env + 8) + uVar1 * 0x44;
    if ((((*(char *)(iVar2 + 0x40) == '\x0f') &&
         (iVar2 = r_co_bdaddr_compare(param_1,iVar2 + 4), iVar2 != 0)) &&
        (iVar2 = *(int *)(_p_llm_env + 8) + uVar1 * 0x44,
        ((param_2 ^ *(byte *)(iVar2 + 0x41)) & 1) == 0)) && (*(byte *)(iVar2 + 0x28) == param_3))
    break;
    uVar1 = uVar1 + 1 & 0xff;
  }
  iVar2 = r_sdk_config_get_opts();
  return uVar1 < *(byte *)(iVar2 + 0xd);
}

