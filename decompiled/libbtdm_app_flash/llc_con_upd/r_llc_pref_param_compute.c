/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llc_con_upd.o -> r_llc_pref_param_compute
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_pref_param_compute(int param_1,int param_2)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined2 uVar5;
  int iVar6;
  uint local_50;
  uint uStack_4c;
  uint uStack_48;
  undefined2 uStack_44;
  int iStack_40;
  uint uStack_3c;
  uint uStack_38;
  uint uStack_34;
  undefined2 uStack_30;
  char cStack_2e;
  byte bStack_2d;
  uint uStack_2c;
  uint uStack_28;
  
  iVar6 = *(int *)(&llc_env + param_1 * 4);
  uVar3 = r_lld_con_offset_get();
  iStack_40 = (uint)*(ushort *)(param_2 + 8) << 1;
  uStack_38 = (uint)*(ushort *)(param_2 + 0x10);
  uVar2 = (uint)*(ushort *)(param_2 + 10) * 2;
  if (uStack_38 < 2) {
    uStack_38 = 2;
  }
  uStack_34 = (uint)*(ushort *)(param_2 + 0x12);
  if (uStack_34 < 2) {
    uStack_34 = 2;
  }
  uStack_30 = (undefined2)param_1;
  cStack_2e = *(char *)(param_2 + 0x27) << 1;
  *(undefined1 *)(param_2 + 0x27) = 1;
  uStack_3c = uVar2;
  if ((*(ushort *)(iVar6 + 0x42) & 1) == 0) {
    if (*(ushort *)(param_2 + 10) == 0) {
      r_assert_err(0,"llc_con_upd.c",0x94);
    }
    uVar3 = ((uVar2 - 1) + uVar3) % uVar2;
    uStack_38 = uStack_38 + 3;
    uStack_34 = uStack_34 + 3;
  }
  bStack_2d = (byte)uVar3 & 1;
  if (((*(char *)(param_2 + 0x2d) == '\0') && (*(char *)(param_2 + 0x2e) == '\0')) &&
     (uVar1 = *(ushort *)(param_2 + 0x16), (uVar1 - 1 & 0xffff) < 0xfffe)) {
    uStack_4c = uStack_38;
    uVar2 = (uint)*(ushort *)(param_2 + 8) << 1;
    uStack_44 = uStack_30;
    local_50 = uVar2;
    if (*(ushort *)(param_2 + 8) == 0) {
      r_assert_err(0,"llc_con_upd.c",0x94);
    }
    uStack_48 = ((uint)uVar1 * 2 + uVar3) % uVar2;
    iVar4 = r_sch_plan_chk(&local_50);
    if (iVar4 != 0) goto _L46;
    *(undefined2 *)(param_2 + 0x2a) = *(undefined2 *)(param_2 + 0x16);
  }
  else {
_L46:
    iVar4 = r_sch_plan_req(&iStack_40);
    uVar2 = uStack_2c;
    if (iVar4 != 0) {
      uVar5 = *(undefined2 *)(param_2 + 10);
      *(undefined2 *)(param_2 + 0x2a) = 0;
      goto _L54;
    }
    if ((*(ushort *)(iVar6 + 0x42) & 1) == 0) {
      if (uStack_2c == 0) {
        r_assert_err("llc_con_upd.c",0x94);
      }
      uStack_28 = (uStack_28 + 1) % uVar2;
    }
    iVar6 = r_lld_con_activity_offset_compute
                      (param_1,*(undefined2 *)(param_2 + 0x14),uStack_2c >> 1 & 0xffff,
                       uStack_28 & 0xffff,0);
    *(short *)(param_2 + 0x2a) = (short)(iVar6 / 0x4e2);
    local_50 = uStack_2c;
  }
  uVar5 = (undefined2)(local_50 >> 1);
_L54:
  *(undefined2 *)(param_2 + 0x28) = uVar5;
  return;
}

