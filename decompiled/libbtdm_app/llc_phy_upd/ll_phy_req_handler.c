/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llc_phy_upd.o -> ll_phy_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int ll_phy_req_handler(int param_1,int param_2,undefined4 param_3)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  bool bVar6;
  
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if (*(char *)(iVar5 + 0x18) == '\0') {
    return 0x24;
  }
  iVar5 = *(int *)(&llc_env + param_1 * 4);
  iVar3 = (**(code **)(_r_ip_funcs_p + 0x678))(1,param_3,*(code **)(_r_ip_funcs_p + 0x678));
  if (iVar3 == 0) {
    iVar3 = 0x1e;
    if (((*(char *)(param_2 + 2) != '\0') && (*(char *)(param_2 + 1) != '\0')) &&
       (((*(ushort *)(iVar5 + 0x42) & 1) == 0 ||
        (iVar3 = (**(code **)(_r_ip_funcs_p + 0x66c))(param_1,9,*(code **)(_r_ip_funcs_p + 0x66c)),
        iVar3 == 0)))) {
      puVar4 = (undefined4 *)
               (**(code **)(_r_modules_funcs_p + 200))
                         (0x10e,param_1 << 8 | 1,0x14,*(code **)(_r_modules_funcs_p + 200));
      *(undefined1 *)(puVar4 + 1) = 9;
      (**(code **)(_r_ip_funcs_p + 0x684))(param_1,5,*(code **)(_r_ip_funcs_p + 0x684));
      iVar5 = _r_ip_funcs_p;
      *puVar4 = *(undefined4 *)(_r_ip_funcs_p + 0x654);
      bVar1 = *(byte *)(param_2 + 1);
      *(byte *)((int)puVar4 + 0xb) = bVar1;
      bVar2 = *(byte *)(param_2 + 2);
      *(byte *)((int)puVar4 + 10) = bVar2;
      if ((uint)bVar1 == (uint)bVar2) {
        bVar6 = (&one_bits)[bVar1] == '\x01';
      }
      else {
        bVar6 = false;
      }
      *(bool *)((int)puVar4 + 0xf) = bVar6;
      (**(code **)(iVar5 + 0x67c))(param_1,1,puVar4,*(code **)(iVar5 + 0x67c));
      (**(code **)(_r_ip_funcs_p + 0x650))(param_1,5,0,*(code **)(_r_ip_funcs_p + 0x650));
      iVar3 = 0;
    }
  }
  else {
    iVar3 = 0x24;
  }
  return iVar3;
}

