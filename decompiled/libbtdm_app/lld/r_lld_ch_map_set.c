/*
 * Last changed at upstream commit ed99228396aaa18935b575d600bc19da38dc4746
 * https://github.com/espressif/esp32c3-bt-lib/commit/ed99228396aaa18935b575d600bc19da38dc4746
 * Upstream date: 2025-01-03 16:50:09 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(fd62b31)
 * Source: libbtdm_app -> lld.o -> r_lld_ch_map_set
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
                    /* WARNING: Could not recover jumptable at 0x0001295e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(iVar2 + 0x18))();
  return;
}

