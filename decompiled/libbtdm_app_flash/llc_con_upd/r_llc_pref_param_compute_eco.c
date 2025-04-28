/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llc_con_upd.o -> r_llc_pref_param_compute_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_pref_param_compute_eco(int param_1,int param_2)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined2 uVar6;
  uint uStack_50;
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
  
  if (((((*(uint *)(param_2 + 0x2c) & 0xffff00) != 0) && (uVar4 = r_lld_con_count_get(), uVar4 < 2))
      && (*(short *)(param_2 + 0x16) != -1)) && (iVar5 = r_llc_proc_state_get(param_2), iVar5 == 2))
  {
    *(undefined2 *)(param_2 + 0x2a) = *(undefined2 *)(param_2 + 0x16);
    *(undefined2 *)(param_2 + 0x28) = *(undefined2 *)(param_2 + 8);
    return;
  }
  iVar5 = *(int *)(&llc_env + param_1 * 4);
  uVar2 = r_lld_con_offset_get();
  iStack_40 = (uint)*(ushort *)(param_2 + 8) << 1;
  uStack_38 = (uint)*(ushort *)(param_2 + 0x10);
  uVar4 = (uint)*(ushort *)(param_2 + 10) * 2;
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
  uStack_3c = uVar4;
  if ((*(ushort *)(iVar5 + 0x42) & 1) == 0) {
    if (*(ushort *)(param_2 + 10) == 0) {
      r_assert_err(0,"llc_con_upd.c",0x94);
    }
    uVar2 = ((uVar4 - 1) + uVar2) % uVar4;
    uStack_38 = uStack_38 + 3;
    uStack_34 = uStack_34 + 3;
  }
  bStack_2d = (byte)uVar2 & 1;
  if (((*(char *)(param_2 + 0x2d) == '\0') && (*(char *)(param_2 + 0x2e) == '\0')) &&
     (uVar1 = *(ushort *)(param_2 + 0x16), (uVar1 - 1 & 0xffff) < 0xfffe)) {
    uStack_4c = uStack_38;
    uVar4 = (uint)*(ushort *)(param_2 + 8) << 1;
    uStack_44 = uStack_30;
    uStack_50 = uVar4;
    if (*(ushort *)(param_2 + 8) == 0) {
      r_assert_err(0,"llc_con_upd.c",0x94);
    }
    uStack_48 = ((uint)uVar1 * 2 + uVar2) % uVar4;
    iVar3 = r_sch_plan_chk(&uStack_50);
    if (iVar3 != 0) goto _L42;
    *(undefined2 *)(param_2 + 0x2a) = *(undefined2 *)(param_2 + 0x16);
  }
  else {
_L42:
    iVar3 = r_sch_plan_req(&iStack_40);
    uVar4 = uStack_2c;
    if (iVar3 != 0) {
      uVar6 = *(undefined2 *)(param_2 + 10);
      *(undefined2 *)(param_2 + 0x2a) = 0;
      goto _L50;
    }
    if ((*(ushort *)(iVar5 + 0x42) & 1) == 0) {
      if (uStack_2c == 0) {
        r_assert_err("llc_con_upd.c",0x94);
      }
      uStack_28 = (uStack_28 + 1) % uVar4;
    }
    iVar5 = r_lld_con_activity_offset_compute
                      (param_1,*(undefined2 *)(param_2 + 0x14),uStack_2c >> 1 & 0xffff,
                       uStack_28 & 0xffff,0);
    *(short *)(param_2 + 0x2a) = (short)(iVar5 / 0x4e2);
    uStack_50 = uStack_2c;
  }
  uVar6 = (undefined2)(uStack_50 >> 1);
_L50:
  *(undefined2 *)(param_2 + 0x28) = uVar6;
  return;
}

