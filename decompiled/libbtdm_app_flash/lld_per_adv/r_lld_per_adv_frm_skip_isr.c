/*
 * Last changed at upstream commit 2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * https://github.com/espressif/esp32c3-bt-lib/commit/2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * Upstream date: 2025-02-25 15:16:47 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(723439d)
 * Source: libbtdm_app_flash -> lld_per_adv.o -> r_lld_per_adv_frm_skip_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_per_adv_frm_skip_isr(uint param_1)

{
  undefined1 uVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined1 *puVar8;
  
  iVar3 = *(int *)(&lld_per_adv_env + param_1 * 4);
  if (iVar3 == 0) {
    r_assert_err(0,"lld_per_adv.c",0x472);
    return;
  }
  iVar7 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar7 + 0x28) & 0x40) != 0) &&
     (iVar7 = r_sdk_config_get_opts_ext(), *(byte *)(iVar7 + 0x2c) < 3)) {
    r_ble_log_internal_x1(0x40480009,(uint)*(byte *)(iVar3 + 0x53) << 8 | param_1);
  }
  if (1 < (byte)(*(char *)(iVar3 + 0x53) - 1U)) {
    r_assert_err(0,"lld_per_adv.c",0x456);
  }
  r_sch_arb_remove(iVar3,1);
  if (*(char *)(iVar3 + 0x53) == '\x02') {
    puVar8 = (undefined1 *)r_ke_msg_alloc(0x208,0,0xff,2);
    uVar1 = *(undefined1 *)(iVar3 + 0x52);
    puVar8[1] = 0;
    *puVar8 = uVar1;
    r_ke_msg_send();
    if (*(int *)(&lld_per_adv_env + param_1 * 4) == 0) {
      iVar3 = r_sdk_config_get_opts_ext();
      if (((*(uint *)(iVar3 + 0x28) & 0x40) != 0) &&
         (iVar3 = r_sdk_config_get_opts_ext(), *(byte *)(iVar3 + 0x2c) < 3)) {
        r_ble_log_internal_x1(0x40080004,param_1);
        return;
      }
    }
    else {
      iVar3 = r_sdk_config_get_opts_ext();
      if (((*(uint *)(iVar3 + 0x28) & 0x40) != 0) &&
         (iVar3 = r_sdk_config_get_opts_ext(), *(byte *)(iVar3 + 0x2c) < 3)) {
        r_ble_log_internal_x1
                  (0x40080002,
                   (uint)*(ushort *)(*(int *)(&lld_per_adv_env + param_1 * 4) + 0x4c) << 0x10 |
                   param_1);
      }
      r_ke_free(*(undefined4 *)(&lld_per_adv_env + param_1 * 4));
      *(undefined4 *)(&lld_per_adv_env + param_1 * 4) = 0;
    }
    return;
  }
  bVar2 = *(byte *)(iVar3 + 0x52);
  *(char *)(iVar3 + 0x16) = *(char *)(iVar3 + 0x16) + rwip_priority;
  iVar3 = *(int *)(&lld_per_adv_env + (uint)bVar2 * 4);
  *(uint *)(iVar3 + 4) = *(int *)(iVar3 + 4) + *(int *)(iVar3 + 0x40) & 0xfffffff;
  *(short *)(iVar3 + 0x4c) = *(short *)(iVar3 + 0x4c) + 1;
  iVar7 = r_lld_read_clock();
  while ((iVar7 - *(int *)(iVar3 + 4) & 0xfffffffU) < 0x7ffffff) {
    *(uint *)(iVar3 + 4) = *(int *)(iVar3 + 4) + *(int *)(iVar3 + 0x40) & 0xfffffff;
    *(short *)(iVar3 + 0x4c) = *(short *)(iVar3 + 0x4c) + 1;
  }
  uVar4 = 0;
  do {
    iVar5 = r_sch_arb_insert(iVar3);
    if (iVar5 == 0) {
      iVar5 = 1;
      goto _L4;
    }
    uVar4 = uVar4 + 1 & 0xff;
    *(char *)(iVar3 + 0x16) = *(char *)(iVar3 + 0x16) + DAT_0001301b;
    *(uint *)(iVar3 + 4) = *(int *)(iVar3 + 4) + *(int *)(iVar3 + 0x40) & 0xfffffff;
    *(short *)(iVar3 + 0x4c) = *(short *)(iVar3 + 0x4c) + 1;
  } while (uVar4 != 0xf);
  iVar5 = 0;
_L4:
  iVar6 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar6 + 0x28) & 0x40) != 0) &&
     (iVar6 = r_sdk_config_get_opts_ext(), *(byte *)(iVar6 + 0x2c) < 3)) {
    r_ble_log_internal_x1
              (0x4048000b,
               iVar5 << 8 | uVar4 << 0x10 | (uint)*(byte *)(iVar3 + 0x53) << 0x18 | (uint)bVar2);
  }
  if (iVar5 == 0) {
    r_assert_param(*(undefined4 *)(iVar3 + 4),iVar7,"lld_per_adv.c",0x13f);
    return;
  }
  *(undefined1 *)(iVar3 + 0x53) = 0;
  return;
}

