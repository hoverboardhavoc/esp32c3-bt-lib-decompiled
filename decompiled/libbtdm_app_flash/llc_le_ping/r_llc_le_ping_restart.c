/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_le_ping.o -> r_llc_le_ping_restart
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_le_ping_restart(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(&llc_env + param_1 * 4);
  iVar3 = r_sdk_config_get_opts_ext();
  if ((*(char *)(iVar3 + 0x1c) != '\0') && ((*(ushort *)(iVar2 + 0x42) & 0x20) != 0)) {
    uVar1 = param_1 << 8 | 1;
    r_ke_timer_set(0x102,uVar1,*(undefined2 *)(iVar2 + 0x3e));
    r_ke_timer_set(0x103,uVar1,*(undefined2 *)(iVar2 + 0x40));
    return;
  }
  return;
}

