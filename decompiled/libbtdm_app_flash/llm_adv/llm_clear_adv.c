/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llm_adv.o -> llm_clear_adv
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 llm_clear_adv(void)

{
  uint uVar1;
  int iVar2;
  
  if (*(char *)(_p_llm_env + 0xd7) != '\x02') {
    *(undefined1 *)(_p_llm_env + 0xd7) = 1;
    uVar1 = r_llm_adv_hdl_to_id(0xff,0);
    iVar2 = r_sdk_config_get_opts();
    if ((uVar1 < *(byte *)(iVar2 + 0xd)) &&
       (*(char *)(*(int *)(_p_llm_env + 8) + uVar1 * 0x44 + 0x40) == '\x01')) {
      r_llm_adv_set_release_hack(uVar1);
      return 0;
    }
  }
  return 0xc;
}

