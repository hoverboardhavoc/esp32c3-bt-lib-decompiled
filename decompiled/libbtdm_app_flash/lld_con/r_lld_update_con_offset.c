/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_update_con_offset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_update_con_offset(void)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  for (uVar1 = 0; iVar2 = r_sdk_config_get_opts(), (int)uVar1 < (int)(uint)*(byte *)(iVar2 + 0xd);
      uVar1 = uVar1 + 1) {
    if (*(int *)(&lld_con_env + uVar1 * 4) != 0) {
      iVar2 = r_llm_plan_elt_get(uVar1 & 0xff);
      if (iVar2 != 0) {
        uVar3 = r_lld_con_offset_get(uVar1 & 0xff);
        *(undefined4 *)(iVar2 + 8) = uVar3;
      }
    }
  }
  return;
}

