/*
 * Last changed at upstream commit 72599d583c232ea78d6461b5b502426c6e5a1ec9
 * https://github.com/espressif/esp32c3-bt-lib/commit/72599d583c232ea78d6461b5b502426c6e5a1ec9
 * Upstream date: 2025-05-19 16:27:45 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(6cfabcd8)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_adv_pkt_rx_send_scan_req_evt_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_pkt_rx_send_scan_req_evt_hack(int param_1)

{
  byte bVar1;
  undefined2 uVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  void *pvVar6;
  undefined1 *puVar7;
  uint uVar8;
  int iVar9;
  byte bVar10;
  undefined1 auStack_34 [4];
  undefined1 uStack_30;
  byte bStack_2f;
  undefined1 auStack_2c [4];
  undefined1 uStack_28;
  
  bVar1 = *(byte *)(_p_lld_env + 0xd8);
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar4 = (uint)bVar1 * 0x14;
  iVar9 = iVar4 + 4;
  if (((*(ushort *)(iVar5 + iVar9) & 0xf) == 3) &&
     (*(char *)(*(int *)(&lld_adv_env + param_1 * 4) + 0x8a) != '\0')) {
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    pvVar6 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                               (*(undefined2 *)(iVar4 + 0x12 + iVar5),
                                *(code **)(_r_plf_funcs_p + 0xbc));
    memcpy(auStack_2c,pvVar6,0xc);
    bVar1 = *(byte *)((int)pvVar6 + 5);
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar8 = (uint)*(ushort *)(iVar4 + 0xe + iVar5);
    if (uVar8 == 0) {
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
      uStack_30 = uStack_28;
      bVar3 = (byte)(*(ushort *)(iVar9 + iVar4) >> 6) & 1;
      bVar10 = bVar1;
    }
    else {
      pvVar6 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                 (uVar8 + 0x18 & 0xffff,*(code **)(_r_plf_funcs_p + 0xbc));
      memcpy(auStack_34,pvVar6,6);
      bVar10 = *(byte *)((int)pvVar6 + 5);
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar2 = *(undefined2 *)(((uVar8 - 0xc60) / 0x34 & 0xff) * 0x34 + iVar4);
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
      bVar3 = (byte)uVar2 & 1;
      if (((*(ushort *)(iVar4 + iVar9) >> 7 & 1) != 0) && ((bVar1 & 0xc0) == 0x40)) {
        bVar3 = bVar3 | 2;
      }
    }
    puVar7 = (undefined1 *)
             (**(code **)(_r_modules_funcs_p + 200))
                       (0x202,0,0xff,8,*(code **)(_r_modules_funcs_p + 200));
    *puVar7 = (char)param_1;
    puVar7[1] = bVar3;
    _uStack_30 = CONCAT11(bVar10,uStack_30);
    memcpy(puVar7 + 2,auStack_34,6);
                    /* WARNING: Could not recover jumptable at 0x00013b74. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_modules_funcs_p + 0xe0))(puVar7,*(code **)(_r_modules_funcs_p + 0xe0));
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00013a54. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x849,*(code **)(_r_plf_funcs_p + 8));
  return;
}

