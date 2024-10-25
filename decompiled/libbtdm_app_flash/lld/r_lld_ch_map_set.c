/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld.o -> r_lld_ch_map_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_ch_map_set(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar1 = _p_lld_env;
  uVar3 = 0;
  uVar4 = 0;
  do {
    if (((int)(uint)*(byte *)((uVar4 >> 3) + param_1) >> (uVar4 & 7) & 1U) != 0) {
      *(char *)(iVar1 + uVar3 + 0xdb) = (char)uVar4;
      uVar3 = uVar3 + 1 & 0xff;
    }
    iVar2 = _r_osi_funcs_p;
    uVar4 = uVar4 + 1 & 0xff;
  } while (uVar4 != 0x25);
  *(char *)(iVar1 + 0x100) = (char)uVar3;
                    /* WARNING: Could not recover jumptable at 0x00012268. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(iVar2 + 0x18))();
  return;
}

