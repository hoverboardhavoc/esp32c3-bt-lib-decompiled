/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llc_le_ping.o -> llc_auth_payl_real_to_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
llc_auth_payl_real_to_handler(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  undefined2 *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar2 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if (*(char *)(iVar2 + 0x20) == '\0') {
    return 0;
  }
  uVar3 = param_3 >> 8;
  iVar4 = *(int *)(&llc_env + uVar3 * 4);
  iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))
                    (param_1,param_2,param_4,*(code **)(_r_plf_funcs_p + 0x38));
  if ((((uVar3 < *(byte *)(iVar2 + 0xd)) && (iVar2 = *(int *)(&llc_env + uVar3 * 4), iVar2 != 0)) &&
      ((*(byte *)(iVar2 + 0x44) & 3) != 3)) && ((*(ushort *)(iVar4 + 0x42) & 0x20) != 0)) {
    puVar1 = (undefined2 *)
             (**(code **)(_r_modules_funcs_p + 200))
                       (0x1103,uVar3,0x57,2,*(code **)(_r_modules_funcs_p + 200));
    iVar2 = _r_ip_funcs_p;
    *puVar1 = (short)(param_3 >> 8);
    (**(code **)(iVar2 + 0x8c))(*(code **)(iVar2 + 0x8c));
    (**(code **)(_r_ip_funcs_p + 0x610))(uVar3,*(code **)(_r_ip_funcs_p + 0x610));
  }
  return 0;
}

