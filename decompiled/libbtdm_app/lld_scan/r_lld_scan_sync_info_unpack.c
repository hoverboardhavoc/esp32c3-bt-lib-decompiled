/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_scan.o -> r_lld_scan_sync_info_unpack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool r_lld_scan_sync_info_unpack(ushort *param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  bool bVar3;
  ushort *puVar4;
  void *pvVar5;
  
  puVar4 = (ushort *)(**(code **)(_r_plf_funcs_p + 0xbc))(param_2,*(code **)(_r_plf_funcs_p + 0xbc))
  ;
  uVar1 = *puVar4;
  *(byte *)(param_1 + 1) = (byte)(((uint)*(byte *)((int)puVar4 + 1) << 8) >> 0xd) & 1;
  *param_1 = (ushort)(((uint)uVar1 << 0x13) >> 0x13);
  puVar4 = (ushort *)
           (**(code **)(_r_plf_funcs_p + 0xbc))
                     (param_2 + 2U & 0xffff,*(code **)(_r_plf_funcs_p + 0xbc));
  param_1[2] = *puVar4;
  pvVar5 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                             (param_2 + 4U & 0xffff,*(code **)(_r_plf_funcs_p + 0xbc));
  memcpy(param_1 + 3,pvVar5,5);
  uVar1 = param_1[5];
  *(byte *)(param_1 + 5) = (byte)uVar1 & 0x1f;
  iVar2 = _r_plf_funcs_p;
  *(byte *)((int)param_1 + 0xb) = (byte)uVar1 >> 5;
  pvVar5 = (void *)(**(code **)(iVar2 + 0xbc))(param_2 + 9U & 0xffff,*(code **)(iVar2 + 0xbc));
  memcpy(param_1 + 6,pvVar5,4);
  pvVar5 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                             (param_2 + 0xdU & 0xffff,*(code **)(_r_plf_funcs_p + 0xbc));
  memcpy(param_1 + 8,pvVar5,3);
  puVar4 = (ushort *)
           (**(code **)(_r_plf_funcs_p + 0xbc))
                     (param_2 + 0x10U & 0xffff,*(code **)(_r_plf_funcs_p + 0xbc));
  bVar3 = false;
  param_1[10] = *puVar4;
  if (*param_1 != 0) {
    bVar3 = 5 < param_1[2];
  }
  return bVar3;
}

