/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_adv_pkt_rx_connect_post
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_pkt_rx_connect_post
               (int param_1,int param_2,void *param_3,void *param_4,void *param_5,undefined1 param_6
               )

{
  ushort uVar1;
  uint uVar2;
  undefined1 *puVar3;
  int iVar4;
  byte bVar5;
  uint uVar6;
  undefined1 uVar7;
  uint uVar8;
  code *pcVar9;
  uint uVar10;
  int iVar11;
  
  bVar5 = *(byte *)(_p_lld_env + 0xd8);
  puVar3 = (undefined1 *)
           (**(code **)(_r_modules_funcs_p + 200))
                     (0x207,0,0xff,0x3c,*(code **)(_r_modules_funcs_p + 200));
  iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar11 = (uint)bVar5 * 0x14;
  uVar1 = *(ushort *)(iVar4 + iVar11 + 10);
  if ((uVar1 & 0xf000) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",1000,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar2 = CONCAT22(uVar1,*(undefined2 *)(iVar4 + iVar11 + 8));
  iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar1 = *(ushort *)(iVar4 + iVar11 + 0xc);
  iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar6 = (uint)(*(ushort *)(iVar4 + iVar11 + 6) >> 0xe);
  uVar8 = (0x270 - (uVar1 & 0x3ff)) + (uint)*(ushort *)(&lld_exp_sync_pos_tab + uVar6 * 2) * -2;
  uVar10 = (uint)(short)uVar8;
  if (((DAT_0001707c & 8) != 0) && ((uVar6 - 2 & 0xff) < 2)) {
    uVar10 = (int)(((uVar8 & 0xffff) + (uint)_DAT_0001707e * -2) * 0x10000) >> 0x10;
  }
  if (0x751 < (uVar10 + 0x4e1 & 0xffff)) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x731,*(code **)(_r_plf_funcs_p + 8));
  }
  for (; (int)uVar10 < 0; uVar10 = (int)(((uVar10 & 0xffff) + 0x271) * 0x10000) >> 0x10) {
    uVar2 = uVar2 - 1 & 0xfffffff;
  }
  puVar3[0x35] = 1;
  *puVar3 = (char)param_1;
  puVar3[1] = 0;
  bVar5 = 1;
  if ((*(ushort *)(*(int *)(&lld_adv_env + param_1 * 4) + 0x74) & 0x10) != 0) {
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    bVar5 = (byte)(*(ushort *)(iVar11 + 4 + iVar4) >> 5) & 1;
  }
  puVar3[0x36] = bVar5;
  uVar7 = 0;
  if (*(short *)(*(int *)(&lld_adv_env + param_1 * 4) + 0x78) != 0) {
    uVar7 = *(undefined1 *)(*(int *)(&lld_adv_env + param_1 * 4) + 0x86);
  }
  puVar3[0x38] = uVar7;
  *(undefined2 *)(puVar3 + 2) = *(undefined2 *)(param_2 + 0xc);
  *(undefined2 *)(puVar3 + 4) = *(undefined2 *)(param_2 + 0xe);
  *(undefined2 *)(puVar3 + 6) = *(undefined2 *)(param_2 + 0x10);
  puVar3[8] = *(undefined1 *)(param_2 + 0x12);
  puVar3[0x1b] = *(undefined1 *)(param_2 + 0x13);
  *(undefined2 *)(puVar3 + 0x1c) = *(undefined2 *)(param_2 + 0x14);
  *(undefined2 *)(puVar3 + 0x1e) = *(undefined2 *)(param_2 + 0x16);
  *(undefined2 *)(puVar3 + 0x20) = *(undefined2 *)(param_2 + 0x18);
  *(undefined2 *)(puVar3 + 0x22) = *(undefined2 *)(param_2 + 0x1a);
  memcpy(puVar3 + 0x24,(void *)(param_2 + 0x1c),5);
  bVar5 = *(byte *)(param_2 + 0x21);
  puVar3[0x29] = bVar5 & 0x1f;
  puVar3[0x2a] = bVar5 >> 5;
  memcpy(puVar3 + 9,param_5,6);
  memcpy(puVar3 + 0xf,param_4,6);
  memcpy(puVar3 + 0x15,param_3,6);
  iVar4 = _r_plf_funcs_p;
  puVar3[0x37] = param_6;
  *(uint *)(puVar3 + 0x30) = uVar2;
  pcVar9 = *(code **)(iVar4 + 0xbc);
  *(short *)(puVar3 + 0x2c) = (short)uVar10;
  iVar4 = (*pcVar9)(0x1000,pcVar9);
  puVar3[0x34] = (byte)((ushort)*(undefined2 *)(iVar4 + iVar11 + 6) >> 0xe);
                    /* WARNING: Could not recover jumptable at 0x0001335a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0xe0))(puVar3);
  return;
}

