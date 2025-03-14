/*
 * Last changed at upstream commit e668c2d101ee46ee1950819607694fb852aecae0
 * https://github.com/espressif/esp32c3-bt-lib/commit/e668c2d101ee46ee1950819607694fb852aecae0
 * Upstream date: 2025-03-14 11:07:43 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(6e312587)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_max_lat_calc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_max_lat_calc(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = *(int *)(&lld_con_env + param_1 * 4);
  if (*(short *)(iVar2 + 0x72) != 0) {
    uVar1 = (500000 - 0x8e300 / *(uint *)(iVar2 + 100)) /
            ((uint)*(ushort *)(_p_lld_env + 0xd4) + (uint)*(ushort *)(iVar2 + 0x7a)) - 1;
    if (*(uint *)(iVar2 + 0x68) <= *(uint *)(iVar2 + 100)) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x649,*(code **)(_r_plf_funcs_p + 8));
    }
    uVar3 = *(uint *)(iVar2 + 0x68) / *(uint *)(iVar2 + 100) - 1;
    if (*(ushort *)(iVar2 + 0x72) < uVar3) {
      uVar3 = (uint)*(ushort *)(iVar2 + 0x72);
    }
    if (uVar1 < uVar3) {
      uVar3 = uVar1;
    }
    *(short *)(iVar2 + 0x72) = (short)uVar3;
    if (499 < uVar3) {
                    /* WARNING: Could not recover jumptable at 0x0001119e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x651);
      return;
    }
  }
  return;
}

