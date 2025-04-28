/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llc_chmap_upd.o -> ll_min_used_channels_ind_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 ll_min_used_channels_ind_handler(int param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar5 = *(int *)(&llc_env + param_1 * 4);
  uVar4 = 0x24;
  if ((((*(ushort *)(iVar5 + 0x42) & 1) != 0) && (uVar4 = 0x30, (*(byte *)(param_2 + 1) & 7) != 0))
     && ((byte)(*(char *)(param_2 + 2) - 2U) < 0x24)) {
    uVar4 = 0;
    uVar2 = (**(code **)(_r_modules_funcs_p + 0xc))(iVar5 + 8,*(code **)(_r_modules_funcs_p + 0xc));
    *(byte *)(iVar5 + 0x1e) = *(byte *)(param_2 + 1) & 7;
    bVar1 = *(byte *)(param_2 + 2);
    *(byte *)(iVar5 + 0x1f) = bVar1;
    if (uVar2 < bVar1) {
      puVar3 = (undefined4 *)
               (**(code **)(_r_modules_funcs_p + 200))
                         (0x10d,param_1 << 8 | 1,0x10,*(code **)(_r_modules_funcs_p + 200));
      *(undefined1 *)(puVar3 + 1) = 6;
      (**(code **)(_r_ip_funcs_p + 0x684))(param_1,0,*(code **)(_r_ip_funcs_p + 0x684));
      *puVar3 = *(undefined4 *)(_r_ip_funcs_p + 0x618);
      (**(code **)(_r_modules_funcs_p + 0xe0))(puVar3,*(code **)(_r_modules_funcs_p + 0xe0));
    }
  }
  return uVar4;
}

