/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_count_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char r_lld_con_count_get(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  cVar1 = '\0';
  for (iVar2 = 0; iVar3 = r_sdk_config_get_opts(), iVar2 < (int)(uint)*(byte *)(iVar3 + 0xd);
      iVar2 = iVar2 + 1) {
    if (*(int *)(&lld_con_env + iVar2 * 4) != 0) {
      cVar1 = cVar1 + '\x01';
    }
  }
  return cVar1;
}

