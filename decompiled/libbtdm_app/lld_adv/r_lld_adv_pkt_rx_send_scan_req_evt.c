/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_adv_pkt_rx_send_scan_req_evt
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_pkt_rx_send_scan_req_evt(int param_1)

{
  undefined2 uVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  void *pvVar6;
  undefined1 *puVar7;
  undefined1 auStack_34 [8];
  undefined1 auStack_2c [20];
  
  bVar2 = *(byte *)(_p_lld_env + 0xd8);
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar3 = (uint)bVar2 * 0x14;
  if (((*(ushort *)(iVar5 + iVar3 + 4) & 0xf) == 3) &&
     (*(char *)(*(int *)(&lld_adv_env + param_1 * 4) + 0x8a) != '\0')) {
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    pvVar6 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                               (*(undefined2 *)(iVar5 + iVar3 + 0x12),
                                *(code **)(_r_plf_funcs_p + 0xbc));
    memcpy(auStack_2c,pvVar6,0xc);
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar4 = (uint)*(ushort *)(iVar3 + 0xe + iVar5);
    if (uVar4 == 0) {
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
      bVar2 = (byte)(*(ushort *)(iVar5 + iVar3 + 4) >> 6) & 1;
    }
    else {
      pvVar6 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                 (uVar4 + 0x18 & 0xffff,*(code **)(_r_plf_funcs_p + 0xbc));
      memcpy(auStack_34,pvVar6,6);
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar3 = ((uVar4 - 0xc60) / 0x34 & 0xff) * 0x34;
      uVar1 = *(undefined2 *)(iVar5 + iVar3);
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
      bVar2 = (byte)*(undefined2 *)(iVar5 + iVar3) & 2 | (byte)uVar1 & 1;
    }
    puVar7 = (undefined1 *)
             (**(code **)(_r_modules_funcs_p + 200))
                       (0x202,0,0xff,8,*(code **)(_r_modules_funcs_p + 200));
    *puVar7 = (char)param_1;
    puVar7[1] = bVar2;
    memcpy(puVar7 + 2,auStack_34,6);
                    /* WARNING: Could not recover jumptable at 0x00013890. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_modules_funcs_p + 0xe0))(puVar7);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0001378a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x7b4);
  return;
}

