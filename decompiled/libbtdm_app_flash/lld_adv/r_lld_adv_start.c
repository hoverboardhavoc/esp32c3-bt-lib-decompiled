/*
 * Last changed at upstream commit 2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * https://github.com/espressif/esp32c3-bt-lib/commit/2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * Upstream date: 2025-02-25 15:16:47 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(723439d)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_adv_start(uint param_1,undefined2 *param_2)

{
  byte bVar1;
  ushort uVar2;
  undefined2 uVar3;
  int iVar4;
  void *__s;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  
  if (*(int *)(&lld_adv_env + param_1 * 4) == 0) {
    __s = (void *)r_ke_malloc(0x9c,0);
    *(void **)(&lld_adv_env + param_1 * 4) = __s;
    if (__s != (void *)0x0) {
      uVar5 = r_lld_read_clock();
      iVar4 = param_1 * 0x5a;
      memset(__s,0,0x9c);
      r_lld_adv_start_init_evt_param(param_1,param_2);
      uVar6 = r_lld_adv_start_set_cs(param_1,param_2,uVar5);
      r_lld_adv_start_update_filter_policy(param_1,param_2);
      iVar7 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar7 + iVar4 + 0x16) = 0x8027;
      if (*(char *)((int)__s + 0x8d) != '\x7f') {
        uVar8 = (*_rwip_rf)(0,_rwip_rf);
        r_bt_rtp_register_rule_cs_idx(param_1,uVar8);
      }
      iVar7 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar7 + iVar4 + 0x18) = 0;
      r_lld_adv_set_tx_power(param_1,uVar6);
      bVar1 = *(byte *)((int)__s + 0x87);
      iVar7 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar7 + iVar4 + 0x1c) = ((ushort)bVar1 * 9 & 0xff) * 0xe + 0x1400;
      iVar7 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar7 + iVar4 + 0xc) = 0xbed6;
      iVar7 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar7 + iVar4 + 0xe) = 0x8e89;
      iVar7 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar7 + iVar4 + 0x10) = 0x5555;
      iVar7 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar7 + iVar4 + 0x12) = 0x55;
      iVar7 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar7 + iVar4 + 0x28) = 0;
      iVar7 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar7 + iVar4 + 0x2a) = 0;
      uVar2 = *(ushort *)((int)__s + 0x74);
      iVar7 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar7 + iVar4 + 0x20) = (ushort)((int)(uint)uVar2 >> 1) & 8;
      bVar1 = *(byte *)((int)__s + 0x8e);
      uVar9 = (uint)*(byte *)((int)__s + 0x90) << 4;
      if ((uVar9 & 0xffffffcf) != 0) {
        r_assert_err(0,"lld_adv.c",0x18e);
      }
      if (((uint)bVar1 << 2 & 0xfffffff3) != 0) {
        r_assert_err(0,"lld_adv.c",399);
      }
      if ((bVar1 & 0xfc) != 0) {
        r_assert_err(0,"lld_adv.c",400);
      }
      iVar7 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar7 + iVar4 + 4) = (ushort)uVar9 | (ushort)((uint)bVar1 << 2) | (ushort)bVar1;
      bVar1 = *(byte *)(param_2 + 0xf);
      if ((param_1 & 0xffffffe0) != 0) {
        r_assert_err(0,"lld_adv.c",0xe6);
      }
      iVar7 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar7 + iVar4 + 2) = (ushort)((bVar1 & 1) << 7) | (ushort)param_1 | 0x800;
      uVar3 = *param_2;
      iVar7 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar7 + iVar4 + 6) = uVar3;
      uVar3 = param_2[1];
      iVar7 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar7 + iVar4 + 8) = uVar3;
      uVar3 = param_2[2];
      iVar7 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar7 + iVar4 + 10) = uVar3;
      uVar9 = (uint)*(byte *)((int)param_2 + 0x1d) << 5;
      if ((uVar9 & 0xffffff1f) != 0) {
        r_assert_err(0,"lld_adv.c",0x641);
      }
      iVar7 = r_emi_get_mem_addr_by_offset(0x400);
      uVar2 = *(ushort *)(iVar7 + iVar4 + 0x26);
      iVar7 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar4 + 0x26 + iVar7) = uVar2 & 0xff1f | (ushort)uVar9;
      r_lld_adv_start_schedule_asap_hack(param_1,param_2,uVar5);
      r_lld_adv_coex_env_reset(__s);
      return 0;
    }
    r_assert_err("lld_adv.c",0xd5b);
  }
  return 0xc;
}

