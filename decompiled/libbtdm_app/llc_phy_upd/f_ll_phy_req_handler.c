/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llc_phy_upd.o -> f_ll_phy_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int f_ll_phy_req_handler(int param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  byte bVar5;
  
  iVar2 = *(int *)(&llc_env + param_1 * 4);
  iVar3 = (**(code **)(_r_ip_funcs_p + 0x678))(1,*(code **)(_r_ip_funcs_p + 0x678));
  if (iVar3 == 0) {
    iVar3 = 0x1e;
    if (((*(char *)(param_2 + 2) != '\0') && (*(char *)(param_2 + 1) != '\0')) &&
       (((*(ushort *)(iVar2 + 0x42) & 1) == 0 ||
        (iVar3 = (**(code **)(_r_ip_funcs_p + 0x66c))(param_1,9,*(code **)(_r_ip_funcs_p + 0x66c)),
        iVar3 == 0)))) {
      puVar4 = (undefined4 *)
               (**(code **)(_r_modules_funcs_p + 200))
                         (0x10e,param_1 << 8 | 1,0x14,*(code **)(_r_modules_funcs_p + 200));
      *(undefined1 *)(puVar4 + 1) = 9;
      (**(code **)(_r_ip_funcs_p + 0x684))(param_1,5,*(code **)(_r_ip_funcs_p + 0x684));
      iVar2 = _r_ip_funcs_p;
      *puVar4 = *(undefined4 *)(_r_ip_funcs_p + 0x654);
      bVar5 = *(byte *)(param_2 + 1);
      *(byte *)((int)puVar4 + 0xb) = bVar5;
      bVar1 = *(byte *)(param_2 + 2);
      *(byte *)((int)puVar4 + 10) = bVar1;
      if ((uint)bVar5 == (uint)bVar1) {
        bVar5 = (&one_bits)[bVar5] & -((&one_bits)[bVar5] == 1);
      }
      else {
        bVar5 = 0;
      }
      *(byte *)((int)puVar4 + 0xf) = bVar5 & 1;
      (**(code **)(iVar2 + 0x67c))(param_1,1,puVar4,*(code **)(iVar2 + 0x67c));
      (**(code **)(_r_ip_funcs_p + 0x650))(param_1,5,0,*(code **)(_r_ip_funcs_p + 0x650));
      iVar3 = 0;
    }
  }
  else {
    iVar3 = 0x24;
  }
  return iVar3;
}

