/*
 * Last changed at upstream commit 72599d583c232ea78d6461b5b502426c6e5a1ec9
 * https://github.com/espressif/esp32c3-bt-lib/commit/72599d583c232ea78d6461b5b502426c6e5a1ec9
 * Upstream date: 2025-05-19 16:27:45 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(6cfabcd8)
 * Source: libbtdm_app_flash -> llc_phy_upd.o -> f_ll_phy_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 f_ll_phy_rsp_handler(int param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  bool bVar4;
  undefined4 uVar5;
  
  uVar5 = 0x1e;
  if ((*(char *)(param_2 + 2) != '\0') && (*(char *)(param_2 + 1) != '\0')) {
    uVar5 = 0;
  }
  if (((*(ushort *)(*(int *)(&llc_env + param_1 * 4) + 0x42) & 1) == 0) ||
     (iVar3 = r_llc_proc_id_get(param_1,0), iVar3 != 9)) {
    uVar5 = 0x24;
  }
  else {
    iVar3 = r_llc_proc_get(param_1,0);
    bVar1 = *(byte *)(param_2 + 2);
    *(byte *)(iVar3 + 10) = *(byte *)(iVar3 + 10) & bVar1;
    bVar2 = *(byte *)(param_2 + 1);
    *(byte *)(iVar3 + 0xb) = *(byte *)(iVar3 + 0xb) & bVar2;
    bVar4 = false;
    if ((uint)bVar1 == (uint)bVar2) {
      bVar4 = (&one_bits)[bVar1] == '\x01';
    }
    *(bool *)(iVar3 + 0xf) = bVar4;
    r_llc_loc_phy_upd_proc_continue_hack(param_1,2,uVar5);
  }
  return uVar5;
}

