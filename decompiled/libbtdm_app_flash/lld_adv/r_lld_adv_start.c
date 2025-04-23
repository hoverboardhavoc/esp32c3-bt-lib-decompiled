/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  byte bVar2;
  ushort uVar3;
  undefined2 uVar4;
  int iVar5;
  void *__s;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 uVar9;
  
  if (*(int *)(&lld_adv_env + param_1 * 4) != 0) {
    return 0xc;
  }
  __s = (void *)r_ke_malloc(0x9c,0);
  *(void **)(&lld_adv_env + param_1 * 4) = __s;
  if (__s == (void *)0x0) {
    r_assert_err(0x10000,0xd4c);
    return 0xc;
  }
  uVar6 = r_lld_read_clock();
  iVar5 = param_1 * 0x5a;
  memset(__s,0,0x9c);
  r_lld_adv_start_init_evt_param(param_1,param_2);
  uVar7 = r_lld_adv_start_set_cs(param_1,param_2,uVar6);
  r_lld_adv_start_update_filter_policy(param_1,param_2);
  iVar8 = r_emi_get_mem_addr_by_offset(0x400);
  *(undefined2 *)(iVar5 + 0x16 + iVar8) = 0x8027;
  if (*(char *)((int)__s + 0x8d) != '\x7f') {
    uVar9 = (*_r_ble_log_internal_x1)(0,_r_ble_log_internal_x1);
    r_bt_rtp_register_rule_cs_idx(param_1,uVar9);
  }
  iVar8 = r_emi_get_mem_addr_by_offset(0x400);
  *(undefined2 *)(iVar5 + 0x18 + iVar8) = 0;
  r_lld_adv_set_tx_power(param_1,uVar7);
  bVar1 = *(byte *)((int)__s + 0x87);
  iVar8 = r_emi_get_mem_addr_by_offset(0x400);
  *(ushort *)(iVar5 + 0x1c + iVar8) = ((ushort)bVar1 * 9 & 0xff) * 0xe + 0x1400;
  iVar8 = r_emi_get_mem_addr_by_offset(0x400);
  *(undefined2 *)(iVar5 + 0xc + iVar8) = 0xbed6;
  iVar8 = r_emi_get_mem_addr_by_offset(0x400);
  *(undefined2 *)(iVar5 + 0xe + iVar8) = 0x8e89;
  iVar8 = r_emi_get_mem_addr_by_offset(0x400);
  *(undefined2 *)(iVar5 + 0x10 + iVar8) = 0x5555;
  iVar8 = r_emi_get_mem_addr_by_offset(0x400);
  *(undefined2 *)(iVar5 + 0x12 + iVar8) = 0x55;
  iVar8 = r_emi_get_mem_addr_by_offset(0x400);
  *(undefined2 *)(iVar5 + 0x28 + iVar8) = 0;
  iVar8 = r_emi_get_mem_addr_by_offset(0x400);
  *(undefined2 *)(iVar5 + 0x2a + iVar8) = 0;
  uVar3 = *(ushort *)((int)__s + 0x74);
  iVar8 = r_emi_get_mem_addr_by_offset(0x400);
  *(ushort *)(iVar5 + 0x20 + iVar8) = (ushort)((int)(uint)uVar3 >> 1) & 8;
  bVar1 = *(byte *)((int)__s + 0x90);
  bVar2 = *(byte *)((int)__s + 0x8e);
  if ((bVar1 & 0xfc) != 0) {
    r_assert_err(0,0x10000,0x18e);
  }
  if ((bVar2 & 0xfc) == 0) {
    if (bVar2 < 4) goto _L1190;
  }
  else {
    r_assert_err(0,0x10000,399);
  }
  r_assert_err(0,0x10000,400);
_L1190:
  iVar8 = r_emi_get_mem_addr_by_offset(0x400);
  *(ushort *)(iVar5 + 4 + iVar8) = (ushort)bVar2 | (ushort)bVar1 << 4 | (ushort)bVar2 << 2;
  bVar1 = *(byte *)(param_2 + 0xf);
  if (0x1f < param_1) {
    r_assert_err(0,0x10000,0xe6);
  }
  iVar8 = r_emi_get_mem_addr_by_offset(0x400);
  *(ushort *)(iVar5 + 2 + iVar8) = (ushort)((bVar1 & 1) << 7) | (ushort)param_1 | 0x800;
  uVar4 = *param_2;
  iVar8 = r_emi_get_mem_addr_by_offset(0x400);
  *(undefined2 *)(iVar5 + 6 + iVar8) = uVar4;
  uVar4 = param_2[1];
  iVar8 = r_emi_get_mem_addr_by_offset(0x400);
  *(undefined2 *)(iVar5 + 8 + iVar8) = uVar4;
  uVar4 = param_2[2];
  iVar8 = r_emi_get_mem_addr_by_offset(0x400);
  *(undefined2 *)(iVar5 + 10 + iVar8) = uVar4;
  bVar1 = *(byte *)((int)param_2 + 0x1d);
  if ((bVar1 & 0xf8) != 0) {
    r_assert_err(0,0x10000,0x641);
  }
  iVar8 = r_emi_get_mem_addr_by_offset(0x400);
  uVar3 = *(ushort *)(iVar8 + iVar5 + 0x26);
  iVar8 = r_emi_get_mem_addr_by_offset(0x400);
  *(ushort *)(iVar5 + 0x26 + iVar8) = uVar3 & 0xff1f | (ushort)bVar1 << 5;
  r_lld_adv_start_schedule_asap_hack(param_1,param_2,uVar6);
  r_lld_adv_coex_env_reset(__s);
  return 0;
}

