/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llm_adv.o -> r_llm_adv_set_all_release
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llm_adv_set_all_release(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  for (uVar1 = 0; iVar2 = r_sdk_config_get_opts(), (int)uVar1 < (int)(uint)*(byte *)(iVar2 + 0xd);
      uVar1 = uVar1 + 1) {
    uVar3 = (uint)*(byte *)(*(int *)(_p_llm_env + 8) + uVar1 * 0x44 + 0x40);
    if ((uVar3 < 0xe) && ((1 << (uVar3 & 0x1f) & 0x3c0eU) != 0)) {
      r_llm_adv_set_release_hack(uVar1 & 0xff);
    }
  }
  return;
}

