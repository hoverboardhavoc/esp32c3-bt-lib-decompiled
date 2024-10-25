/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc.o -> r_llc_role_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 r_llc_role_get(uint param_1,undefined1 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = r_sdk_config_get_opts();
  uVar2 = 2;
  if (param_1 < *(byte *)(iVar1 + 0xd)) {
    iVar1 = *(int *)(&llc_env + param_1 * 4);
    uVar2 = 2;
    if (((iVar1 != 0) && ((*(byte *)(iVar1 + 0x44) & 3) != 3)) &&
       ((*(ushort *)(iVar1 + 0x42) & 1) != 0)) {
      uVar2 = 0;
      *param_2 = 0;
    }
  }
  return uVar2;
}

